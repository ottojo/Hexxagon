/**
 * @file GameScreen.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include "screens/GameScreen.h"
#include <chrono>
#include <sstream>
#include <messages/client/GameMove.h>

bool GameScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        auto start = std::chrono::system_clock::now();
        auto click = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        auto axialTileCoordinate = view.getCurrentCoordinate(window, click);
        auto tileIndex = HexGridTools::indexFromAxial(axialTileCoordinate);
        auto end = std::chrono::system_clock::now();
        auto duration = end - start;

        if (tileIndex.has_value()) {
            std::cout << "Click on " << tileIndex.value() << " "
                      << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() << "µs" << std::endl;

            if (currentState == State::PLAYING) {
                if (!firstSelection.has_value()) {
                    // Select first Tile
                    firstSelection.emplace(tileIndex.value());
                    view.select(tileIndex.value());
                } else {
                    // Select second Tile, send move
                    GameMove g;
                    g.userId = self.id;
                    g.gameId = gameId;
                    g.moveFrom = firstSelection.value();
                    g.moveTo = tileIndex.value();
                    serverConnection.send(g);
                    firstSelection.reset();
                    view.deselect();
                }
            }
            return true;
        }
    }
    return false;
}

void GameScreen::updateGameStatus(GameStatus gameStatus) {
    std::cout << "Received GameStatus" << std::endl;
    game.setBoard(gameStatus.board);
    view.setBoard(game.getBoard());
    if (gameStatus.activePlayer == self.id) {
        currentState = State::PLAYING;
        std::cout << "Active Player" << std::endl;
    } else {
        currentState = State::WAITING;
    }
}

ProgramState GameScreen::render(sf::RenderTarget &window) {
    view.render(window);
    return ProgramState::IN_GAME;
}

GameScreen::GameScreen(ServerConnection &connection, Player &self) :
        game(),
        serverConnection{connection},
        self{self},
        view(game.getBoard()) {
    serverConnection.gameStatusListener.subscribe(
            std::bind(&GameScreen::updateGameStatus, this, std::placeholders::_1));
    serverConnection.gameStartedListener.subscribe([&](const GameStarted &gameStarted) {
        gameId = gameStarted.gameId;
    });
}

void GameScreen::init() {

}
