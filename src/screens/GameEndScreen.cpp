//
// Created by jonas on 29.12.19.
//

#include <util/GraphicsUtil.h>
#include <util/FontUtil.h>
#include "screens/GameEndScreen.h"

ProgramState GameEndScreen::render(sf::RenderTarget &window) {
    const std::lock_guard<std::mutex> lock(winnerLabelMutex);
    winnerLabel.setPosition(0.5f * window.getSize().x, 0.5f * window.getSize().y);
    window.draw(winnerLabel);
    returnToMainMenuButton->setPosition(0.5f * window.getSize().x - 0.5 * returnToMainMenuButton->getSize().x,
                                        winnerLabel.getPosition().y + winnerLabel.getLocalBounds().getSize().y + 20);
    gui.draw();
    return nextState;
}

bool GameEndScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    if (event.type == sf::Event::Resized) {
        gui.setView(window.getView());
    }
    gui.handleEvent(event);
    return false;
}

void GameEndScreen::init() {
    nextState = ProgramState::GAME_END;
}

void GameEndScreen::onGameStatus(const GameStatus &gameStatus) {
    const std::lock_guard<std::mutex> lock(winnerLabelMutex);
    if (!gameStatus.isClosed) {
        return;
    }

    if (gameStatus.playerOnePoints == gameStatus.playerTwoPoints || gameStatus.tie) {
        winnerLabel.setString("Tie!");
        std::cout << "Game ended, tie!" << std::endl;
    } else {
        bool won;
        if (gameStatus.playerOne == self.id) {
            won = gameStatus.playerOnePoints > gameStatus.playerTwoPoints;
        } else {
            won = gameStatus.playerTwoPoints > gameStatus.playerOnePoints;
        }
        if (won) {
            winnerLabel.setString("You have won!");
            std::cout << "Game ended, you have won!" << std::endl;
        } else {
            winnerLabel.setString("You lost.");
            std::cout << "Game ended, you lost." << std::endl;
        }
    }
    util::GraphicsUtil::setOriginToCenter(winnerLabel);
}

GameEndScreen::GameEndScreen(ServerConnection &connection, Player &self, sf::RenderTarget &window) :
        serverConnection{connection},
        self{self},
        winnerLabel{"", util::FontUtil::getDefaultFont()},
        gui{window},
        returnToMainMenuButton{tgui::Button::create("Return to menu")} {
    connection.gameStatusListener.subscribe(std::bind(&GameEndScreen::onGameStatus, this, std::placeholders::_1));
    winnerLabel.setCharacterSize(100);
    winnerLabel.setFillColor(sf::Color::White);

    returnToMainMenuButton->setPosition("(parent.size - size) / 2");
    returnToMainMenuButton->onClick.connect([&]() {
        nextState = ProgramState::MAIN_MENU;
    });
    gui.add(returnToMainMenuButton);
}
