//
// Created by jonas on 29.12.19.
//

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
    if (event.type == sf::Event::Resized) {
        gui.setView(window.getView());
    }
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

    lobbyListBox->removeAllItems();
    for (const auto &lobby:lobbies) {
        lobbyListBox->addItem(lobby.name + " (" + lobby.id + ")", lobby.id);
    }
}

void LobbySelectScreen::newLobby() {
    CreateNewLobby c;
    c.userId = self.id;
    c.lobbyName = lobbyNameEditBox->getText();
    serverConnection.send(c);
    init();
}

LobbySelectScreen::LobbySelectScreen(ServerConnection &serverConnection, Player &self, sf::RenderTarget &window) :
        window{window},
        serverConnection{serverConnection},
        self{self},
        gui{window},
        lobbyNameEditBox{tgui::EditBox::create()},
        createLobbyButton{tgui::Button::create("Create Lobby")},
        refreshButton{tgui::Button::create("Refresh")},
        lobbyListBox{tgui::ListBox::create()} {
    serverConnection.availableLobbiesListener.subscribe(
            std::bind(&LobbySelectScreen::onAvailableLobbies, this, std::placeholders::_1));
    // Center lobbyListBox
    lobbyListBox->setSize("80%", "60%");
    lobbyListBox->setPosition("(parent.size - size) / 2");
    gui.add(lobbyListBox);

    lobbyNameEditBox->setDefaultText("New Lobby Name");
    lobbyNameEditBox->setPosition(tgui::bindLeft(lobbyListBox),
                                  tgui::bindBottom(lobbyListBox) + 20);
    gui.add(lobbyNameEditBox);

    createLobbyButton->setPosition(tgui::bindRight(lobbyNameEditBox) + 20, tgui::bindTop(lobbyNameEditBox));
    createLobbyButton->connect("pressed", std::bind(&LobbySelectScreen::newLobby, this));
    gui.add(createLobbyButton);

    refreshButton->setPosition(tgui::bindRight(lobbyListBox) - tgui::bindWidth(refreshButton),
                               tgui::bindBottom(lobbyListBox) + 20);
    refreshButton->connect("pressed", std::bind(&LobbySelectScreen::init, this));
    gui.add(refreshButton);

}
