//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_PROGRAM_H
#define HEXXAGON_PROGRAM_H


#include <screens/GameEndScreen.h>
#include "ProgramState.h"
#include "network/ServerConnection.h"
#include "screens/MenuScreen.h"
#include "screens/GameScreen.h"
#include "screens/LobbySelectScreen.h"

class Program {
private:

    // state <-> current screen
    ProgramState state = ProgramState::MAIN_MENU;
    ServerConnection serverConnection;
    sf::RenderWindow &window;

    MenuScreen menuScreen;
    LobbySelectScreen lobbySelectScreen;
    GameScreen gameScreen;
    GameEndScreen gameEndScreen;
    // if true, init() should be called on the current screen.
    bool initNextScreen = true;

    Player self;

    // Main loop: (optionally) init screen, dispatch events to screen, render screen
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

                // Resize event should be handled by all screens, to allow for tgui rescaling before screen is active
                menuScreen.handleInput(event, window);
                lobbySelectScreen.handleInput(event, window);
                gameScreen.handleInput(event, window);
                gameEndScreen.handleInput(event, window);
            }
            screen.handleInput(event, window);
        }
        auto newState = screen.render(window);
        if (newState != state) {
            // Call init() on new screen whenever screen switches
            initNextScreen = true;
        }
        state = newState;
    }

public:

    explicit Program(sf::RenderWindow &window);

    /**
     * Main game loop, returns once window is closed
     */
    void run();
};


#endif //HEXXAGON_PROGRAM_H
