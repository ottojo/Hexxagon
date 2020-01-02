//
// Created by jonas on 29.12.19.
//

#include <util/FontUtil.h>
#include <iostream>
#include "screens/LobbySelectScreen.h"
#include "view/TextBox.h"
#include <network/messages/client/GetAvailableLobbies.h>

ProgramState LobbySelectScreen::render(sf::RenderTarget &window) {

    window.draw(lobbyNameTextBox);
    window.draw(refreshButton);
    window.draw(createLobbyButton);

    return ProgramState::LOBBY_SELECT;
}

bool LobbySelectScreen::handleInput(sf::Event event, sf::RenderTarget &window) {

    if (event.type == sf::Event::TextEntered) {
        lobbyNameTextBox.handleTextEvent(event.text);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        auto clickLocation = window.mapPixelToCoords(sf::Vector2i{event.mouseButton.x, event.mouseButton.y});
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (refreshButton.getGlobalBounds().contains(clickLocation)) {
                init();
            }
            lobbyNameTextBox.setActive(lobbyNameTextBox.getGlobalBounds().contains(clickLocation));
        }
    }

    return false;
}

void LobbySelectScreen::init() {
    GetAvailableLobbies g;
    g.userId = self.id;
    serverConnection.send(g);
}

void LobbySelectScreen::onAvailableLobbies(AvailableLobbies availableLobbies) {
    std::cout << "Got " << availableLobbies.lobbies.size() << " available lobbies" << std::endl;
}

LobbySelectScreen::LobbySelectScreen(ServerConnection &serverConnection, Player &self) :
        lobbyNameTextBox{300, 50, "Lobby Name", FontUtil::getDefaultFont()},
        createLobbyButton{250, 50, "Create Lobby", FontUtil::getDefaultFont()},
        serverConnection{serverConnection},
        self{self},
        refreshButton(250, 50, "Refresh Lobbies", FontUtil::getDefaultFont()) {
    serverConnection.availableLobbiesListener.subscribe(
            std::bind(&LobbySelectScreen::onAvailableLobbies, this, std::placeholders::_1));
    lobbyNameTextBox.setActive(true);
    lobbyNameTextBox.setPosition(50, 100);
    refreshButton.setPosition(100, 400);
    createLobbyButton.setPosition(400, 100);
}
