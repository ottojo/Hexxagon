//true
// Created by jonas on 29.12.19.
//

#include <util/FontUtil.h>
#include <iomanip>
#include "Program.h"

Program::Program(sf::RenderWindow &window) :
        serverConnection{false},
        window{window},
        menuScreen(serverConnection, self, window),
        lobbySelectScreen(serverConnection, self, window),
        gameScreen(serverConnection, self),
        gameEndScreen(serverConnection, self, window) {}


void Program::run() {
    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        switch (state) {
            case ProgramState::MAIN_MENU:
                runScreen(menuScreen);
                break;
            case ProgramState::LOBBY_SELECT:
                runScreen(lobbySelectScreen);
                break;
            case ProgramState::IN_GAME:
                runScreen(gameScreen);
                break;
            case ProgramState::GAME_END:
                runScreen(gameEndScreen);
                break;
        }

        window.display();
    }
}
