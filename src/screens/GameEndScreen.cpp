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
    return ProgramState::GAME_END;
}

bool GameEndScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    return false;
}

void GameEndScreen::init() {

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

GameEndScreen::GameEndScreen(ServerConnection &connection, Player &self) :
        serverConnection{connection},
        self{self},
        winnerLabel{"", util::FontUtil::getDefaultFont()} {
    connection.gameStatusListener.subscribe(std::bind(&GameEndScreen::onGameStatus, this, std::placeholders::_1));
    winnerLabel.setCharacterSize(100);
    winnerLabel.setFillColor(sf::Color::White);
}
