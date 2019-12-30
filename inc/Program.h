//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_PROGRAM_H
#define HEXXAGON_PROGRAM_H


#include <screens/LobbyScreen.h>
#include <screens/GameEndScreen.h>
#include "ProgramState.h"
#include "ServerConnection.h"
#include "screens/MenuScreen.h"
#include "screens/GameScreen.h"
#include "screens/LobbySelectScreen.h"

class Program {
private:
    ProgramState state = ProgramState::MAIN_MENU;
    ServerConnection serverConnection;
    sf::RenderWindow &window;

    MenuScreen menuScreen;
    GameScreen gameScreen;
    LobbyScreen lobbyScreen;
    LobbySelectScreen lobbySelectScreen;
    GameEndScreen gameEndScreen;

    template<typename ScreenType>
    void runScreen(ScreenType &screen) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                //continue;
            }
            screen.handleInput(event, window);
        }
        state = screen.render(window);
    }

public:

    explicit Program(sf::RenderWindow &window);

    void run();
};


#endif //HEXXAGON_PROGRAM_H
