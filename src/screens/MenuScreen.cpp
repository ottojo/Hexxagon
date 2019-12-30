//
// Created by jonas on 24.12.19.
//

#include <iostream>
#include <util/FontUtil.h>
#include <util/GraphicsUtil.h>
#include "screens/MenuScreen.h"

ProgramState MenuScreen::render(sf::RenderTarget &window) {

    auto[w, h] = window.getSize();
    sf::Vector2f center = 0.5f * window.mapPixelToCoords({static_cast<int>(w), static_cast<int>(h)});

    util::GraphicsUtil::setOriginToCenter(lobbyText);
    lobbyText.setPosition(center + sf::Vector2f{0, -60});

    util::GraphicsUtil::setOriginToCenter(serverNameText);
    serverNameText.setPosition(center + sf::Vector2f{0, -20});

    util::GraphicsUtil::setOriginToCenter(connectText);
    connectText.setPosition(center + sf::Vector2f{0, 20});

    util::GraphicsUtil::setOriginToCenter(exitText);
    exitText.setPosition(center + sf::Vector2f{0, 60});


    window.draw(lobbyText);
    window.draw(serverNameText);
    window.draw(connectText);
    window.draw(exitText);

    return ProgramState::MAIN_MENU;
}

bool MenuScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    if (event.type == sf::Event::MouseButtonPressed) {

        auto connectTextBounds = connectText.getGlobalBounds();
        if (connectTextBounds.contains(
                window.mapPixelToCoords(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}))) {
            serverConnection.connect("hexxagon.otto.cool", 4444);
        }
    }
    return false;
}

MenuScreen::MenuScreen(ServerConnection &serverConnection) :
        serverConnection{serverConnection},
        lobbyText("Find Lobby", FontUtil::getDefaultFont()),
        serverNameText("hexxagon.otto.cool:4444", FontUtil::getDefaultFont()),
        connectText("Connect", FontUtil::getDefaultFont()),
        exitText("Exit Game", FontUtil::getDefaultFont()) {
    serverConnection.welcomeListener.subscribe(
            std::bind(&MenuScreen::handleWelcome, this, std::placeholders::_1));
}

void MenuScreen::handleWelcome(Welcome welcomeMessage) {
    std::cout << "Welcome message received in menu screen: " << welcomeMessage.welcomeMessage << " User: "
              << welcomeMessage.userId << std::endl;
}

void MenuScreen::init() {

}
