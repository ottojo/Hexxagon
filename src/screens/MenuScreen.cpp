//
// Created by jonas on 24.12.19.
//

#include <iostream>
#include "screens/MenuScreen.h"

ProgramState MenuScreen::render(sf::RenderTarget &window) const {

    static bool first = true;
    if (first) {
        serverConnection.connect("hexxagon.otto.cool", 4444);
        first = false;
    }

    return ProgramState::MAIN_MENU;
}

bool MenuScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    return false;
}

MenuScreen::MenuScreen(ServerConnection &serverConnection) : serverConnection{serverConnection} {
    std::cout << "MenuScreen constructed" << std::endl;
    serverConnection.welcomeListener.subscribe(
            std::bind(&MenuScreen::handleWelcome, this, std::placeholders::_1));
}

void MenuScreen::handleWelcome(Welcome welcomeMessage) {
    std::cout << "Welcome message received in menu screen: " << welcomeMessage.welcomeMessage << " User: "
              << welcomeMessage.userId << std::endl;
}
