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

    return nextState;
}

bool MenuScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        auto click = window.mapPixelToCoords(sf::Vector2i{event.mouseButton.x, event.mouseButton.y});
        auto connectTextBounds = connectText.getGlobalBounds();
        if (connectTextBounds.contains(click)) {
            lobbyText.setFillColor(sf::Color::Red);
            serverConnection.connect("hexxagon.otto.cool", 4444);
            return true;
        }

        auto lobbyTextBounds = lobbyText.getGlobalBounds();
        if (lobbyTextBounds.contains(click)) {
            if (serverConnection.isConnected()) {
                nextState = ProgramState::LOBBY_SELECT;
            }
        }

    }
    return false;
}

MenuScreen::MenuScreen(ServerConnection &ServerConnection, Player &self) :
        serverConnection{ServerConnection},
        self{self},
        lobbyText("Find Lobby", FontUtil::getDefaultFont()),
        serverNameText("hexxagon.otto.cool:4444", FontUtil::getDefaultFont()),
        connectText("Connect", FontUtil::getDefaultFont()),
        exitText("Exit Game", FontUtil::getDefaultFont()) {
    ServerConnection.welcomeListener.subscribe(
            std::bind(&MenuScreen::handleWelcome, this, std::placeholders::_1));
    lobbyText.setFillColor(sf::Color::Red);
}

void MenuScreen::handleWelcome(Welcome welcomeMessage) {
    std::cout << "Welcome message received in menu screen: " << welcomeMessage.welcomeMessage << " User: "
              << welcomeMessage.userId << std::endl;
    lobbyText.setFillColor(sf::Color::Green);
    self.id = welcomeMessage.userId;
}

void MenuScreen::init() {

}
