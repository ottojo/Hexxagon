//
// Created by jonas on 29.12.19.
//

#include <util/FontUtil.h>
#include <iostream>
#include "screens/LobbySelectScreen.h"
#include "view/TextBox.h"
#include <network/messages/client/GetAvailableLobbies.h>
#include <network/messages/client/CreateNewLobby.h>

ProgramState LobbySelectScreen::render(sf::RenderTarget &) {
    gui.draw();

    return ProgramState::LOBBY_SELECT;
}

bool LobbySelectScreen::handleInput(sf::Event event, sf::RenderTarget &) {

    gui.handleEvent(event);
    return false;
}

void LobbySelectScreen::init() {
    GetAvailableLobbies g;
    g.userId = self.id;
    serverConnection.send(g);
}

void LobbySelectScreen::onAvailableLobbies(const AvailableLobbies &availableLobbies) {
    std::cout << "Got " << availableLobbies.lobbies.size() << " available lobbies" << std::endl;
    lobbies = availableLobbies.lobbies;
}

void LobbySelectScreen::newLobby() {
    CreateNewLobby c;
    c.userId = self.id;
    c.lobbyName = lobbyNameTextBox->getText();
    serverConnection.send(c);
    init();
}

LobbySelectScreen::LobbySelectScreen(ServerConnection &serverConnection, Player &self, sf::RenderTarget &window) :
        window{window},
        serverConnection{serverConnection},
        self{self},
        gui{window},
        lobbyNameTextBox{tgui::TextBox::create()},
        createLobbyButton{tgui::Button::create("Create Lobby")},
        refreshButton{tgui::Button::create("Refresh")} {
    serverConnection.availableLobbiesListener.subscribe(
            std::bind(&LobbySelectScreen::onAvailableLobbies, this, std::placeholders::_1));
    lobbyNameTextBox->setPosition(50, 100);
    gui.add(lobbyNameTextBox);

    createLobbyButton->setPosition(400, 100);
    createLobbyButton->connect("pressed", std::bind(&LobbySelectScreen::newLobby, this));
    gui.add(createLobbyButton);

    refreshButton->setPosition(500, 500);
    refreshButton->connect("pressed", std::bind(&LobbySelectScreen::init, this));
    gui.add(refreshButton);


}
