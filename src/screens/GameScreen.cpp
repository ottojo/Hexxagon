/**
 * @file GameScreen.cpp
 * @author jonas
 * @date 12/8/19
 */

#include "screens/GameScreen.h"
#include <sstream>
#include <messages/client/GameMove.h>
#include <set>

bool GameScreen::isOwnTile(int tileIndex) {
    if (lastGameStatus.has_value()) {
        // Determine if we are PLAYERONE or PLAYERTWO
        // TODO determine PLAYERONE or PLAYERTWO not on every click, but once (or on game status update)
        TileState role;
        if (self.id == lastGameStatus.value().playerOne) {
            role = TileState::PLAYERONE;
        } else {
            role = TileState::PLAYERTWO;
        }

        if (view.getBoard().getTiles().at(tileIndex).getState() == role) {
            return true;
        }
    }
    return false;
}

bool GameScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        const std::lock_guard<std::mutex> lock(gameViewMutex);
        auto click = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        auto axialTileCoordinate = view.getCurrentCoordinate(window, click);
        auto tileIndex = HexGridTools::indexFromAxial(axialTileCoordinate);


        if (tileIndex.has_value()) {
            std::cout << "clicked on " << tileIndex.value() << std::endl;
            if (currentState == State::PLAYING) {
                if (!firstSelection.has_value()) {
                    // Select first Tile
                    if (isOwnTile(tileIndex.value())) {
                        firstSelection.emplace(tileIndex.value());
                        view.select(tileIndex.value());
                        std::cout << "made first selection" << std::endl;

                        return true;
                    }
                } else {
                    // Get all valid moves
                    std::set<int> validMoves;
                    auto neighbours = HexGridTools::neighbours(
                            HexGridTools::axialFromIndex(firstSelection.value()).value());
                    auto indirectNeighbours = HexGridTools::indirectNeighbours(
                            HexGridTools::axialFromIndex(firstSelection.value()).value());

                    for (const auto &n : neighbours) {
                        auto index = HexGridTools::indexFromAxial(n);
                        if (!index.has_value()) {
                            continue;
                        }
                        if (view.getBoard().getTiles().at(index.value()).getState() == TileState::FREE) {
                            validMoves.emplace(index.value());
                        }
                    }
                    for (const auto &n : indirectNeighbours) {
                        auto index = HexGridTools::indexFromAxial(n);
                        if (!index.has_value()) {
                            continue;
                        }
                        if (view.getBoard().getTiles().at(index.value()).getState() == TileState::FREE) {
                            validMoves.emplace(index.value());
                        }
                    }
                    std::cout << "found " << validMoves.size() << " valid moves" << std::endl;
                    // If move is valid
                    if (validMoves.find(tileIndex.value()) != validMoves.end()) {
                        // Select second Tile, send move
                        std::cout << "made second selection" << std::endl;
                        GameMove g;
                        g.userId = self.id;
                        g.gameId = gameId;
                        g.moveFrom = firstSelection.value();
                        g.moveTo = tileIndex.value();
                        serverConnection.send(g);
                    } else {
                        std::cout << "invalid move" << std::endl;
                    }
                }
            }
        }
        firstSelection.reset();
        view.deselect();
        return true;
    }
    return false;
}

void GameScreen::updateGameStatus(const GameStatus &gameStatus) {
    std::cout << "Received GameStatus" << std::endl;
    lastGameStatus.emplace(gameStatus);
    const std::lock_guard<std::mutex> lock(gameViewMutex);
    view.setBoard(lastGameStatus.value().board);
    if (gameStatus.activePlayer == self.id) {
        currentState = State::PLAYING;
        std::cout << "Active Player" << std::endl;
    } else {
        currentState = State::WAITING;
    }
}

ProgramState GameScreen::render(sf::RenderTarget &window) {
   // TODO: scale background
    window.draw(backgroundSprite);

    const std::lock_guard<std::mutex> lock(gameViewMutex);
    view.render(window);
    if (lastGameStatus->isClosed) {
        return ProgramState::GAME_END;
    } else {
        return ProgramState::IN_GAME;
    }
}

GameScreen::GameScreen(ServerConnection &connection, Player &self) :
        serverConnection{connection},
        self{self} {
    serverConnection.gameStatusListener.subscribe(
            std::bind(&GameScreen::updateGameStatus, this, std::placeholders::_1));
    serverConnection.gameStartedListener.subscribe([&](const GameStarted &gameStarted) {
        gameId = gameStarted.gameId;
    });
    if (not backgroundTexture.loadFromFile("assets/space.jpg")) {
        std::cerr << "Could not load background texture. (\"assets/space.jpg\")" << std::endl;
        std::exit(1);
    }
    backgroundTexture.setSmooth(true);
    backgroundSprite.setTexture(backgroundTexture);
}

void GameScreen::init() {
    lastGameStatus.reset();
}
