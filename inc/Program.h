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
    bool initNextScreen = true;

    Player self;

    template<typename ScreenType>
    void runScreen(ScreenType &screen) {
        if (initNextScreen) {
            screen.init();
            initNextScreen = false;
        }

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            screen.handleInput(event, window);
        }
        auto newState = screen.render(window);
        if (newState != state) {
            initNextScreen = true;
        }
        state = newState;
    }

public:

    explicit Program(sf::RenderWindow &window);

    void run();
};


#endif //HEXXAGON_PROGRAM_H
