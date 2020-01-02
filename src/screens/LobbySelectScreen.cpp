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

    return ProgramState::LOBBY_SELECT;
}

bool LobbySelectScreen::handleInput(sf::Event event, sf::RenderTarget &window) {

    if (event.type == sf::Event::TextEntered) {
        if (lobbyNameTextBox.isActive()) {
            if (event.text.unicode == '\b') {
                // Backspace
                // TODO handle empty textbox
                // TODO move input handling to textbox
                sf::String newString = lobbyNameTextBox.getText();
                newString.erase(newString.getSize() - 1);
                lobbyNameTextBox.setText(newString);
            } else {
                lobbyNameTextBox.setText(lobbyNameTextBox.getText() + event.text.unicode);
            }
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
        lobbyNameTextBox{"Lobby Name", 300, FontUtil::getDefaultFont()},
        serverConnection{serverConnection},
        self{self},
        refreshButton(200, 40, "Refresh Lobbies", FontUtil::getDefaultFont()){
    serverConnection.availableLobbiesListener.subscribe(
            std::bind(&LobbySelectScreen::onAvailableLobbies, this, std::placeholders::_1));
    lobbyNameTextBox.setActive(true);
    lobbyNameTextBox.setPosition(100, 300);
    refreshButton.setPosition(100, 400);
}
