//
// Created by jonas on 29.12.19.
//

#include <util/FontUtil.h>
#include <iomanip>
#include "Program.h"

Program::Program(sf::RenderWindow &window) :
        window{window},
        menuScreen(serverConnection, self),
        lobbySelectScreen(serverConnection, self) {
    FontUtil::init("arial.ttf");
}


void Program::run() {

    float fps = 1;

    sf::Text fpsText("", FontUtil::getDefaultFont());
    fpsText.setFillColor(sf::Color::Blue);

    sf::Text positionText("", FontUtil::getDefaultFont());
    positionText.setFillColor(sf::Color::Blue);
    positionText.setPosition(0, 50);

    sf::Clock clock;
    while (window.isOpen()) {
        window.clear(sf::Color::Black);


        switch (state) {
            case ProgramState::MAIN_MENU:
                runScreen(menuScreen);
                break;
            case ProgramState::LOBBY_SELECT:
                runScreen(lobbySelectScreen);
                break;
            case ProgramState::LOBBY:
                runScreen(lobbyScreen);
                break;
            case ProgramState::IN_GAME:
                runScreen(gameScreen);
                break;
            case ProgramState::GAME_END:
                runScreen(gameEndScreen);
                break;
        }


        std::stringstream stream;
        stream << "FPS: " << std::setfill('0') << std::setw(8) << std::fixed << std::setprecision(2) << fps;
        fpsText.setString(stream.str());
        window.draw(fpsText);
        window.draw(positionText);

        window.display();

        fps = 1 / clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}
