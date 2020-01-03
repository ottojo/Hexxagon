//
// Created by jonas on 29.12.19.
//

#include <iostream>
#include "screens/LobbySelectScreen.h"
#include "view/TextBox.h"
#include <network/messages/client/GetAvailableLobbies.h>
#include <network/messages/client/CreateNewLobby.h>
#include <network/messages/client/JoinLobby.h>
#include <network/messages/client/LeaveLobby.h>

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

    lobbyListBox->removeAllItems();
    for (const auto &lobby:availableLobbies.lobbies) {
        sf::String lobbyText = lobby.name;
        if (lobby.player1.has_value()) {
            lobbyText += " (" + lobby.player1->name;
            if (lobby.player2.has_value()) {
                lobbyText += ", " + lobby.player2->name;
            }
            lobbyText += ")";
        }
        lobbyListBox->addItem(lobbyText + " (" + lobby.id + ")", lobby.id);
    }
}

void LobbySelectScreen::newLobby() {
    CreateNewLobby c;
    c.userId = self.id;
    c.lobbyName = lobbyNameEditBox->getText();
    serverConnection.send(c);
    init();
}

void LobbySelectScreen::joinLobby() {
    leaveLobby();
    JoinLobby j;
    j.userId = self.id;
    j.userName = "HansWurst";
    j.lobbyId = lobbyListBox->getSelectedItemId();

    serverConnection.send(j);
}

void LobbySelectScreen::leaveLobby() {
    if (currentLobby.has_value()) {
        LeaveLobby l;
        l.userId = self.id;
        l.lobbyId = currentLobby->id;
        serverConnection.send(l);
        currentLobby.reset();
        // TODO remove race condition (sending "leave" and "join" at the same time)
        //  (Probably not relevant, can join multiple lobbies at the same time)
    }
}

void LobbySelectScreen::onLobbyJoined(const LobbyJoined &lobbyJoined) {
    if (lobbyJoined.successfullyJoined) {
        statusLabel->setText("Joining lobby was successful.");
        statusLabel->getRenderer()->setTextColor(sf::Color::Green);
    } else {
        statusLabel->setText("Joining lobby was not successful.");
        statusLabel->getRenderer()->setTextColor(sf::Color::Red);
    }
}

void LobbySelectScreen::onLobbyStatus(const LobbyStatus &lobbyStatus) {
    currentLobby = lobbyStatus.lobby;
    leaveLobbyButton->setEnabled(currentLobby->player2->id == self.id);
}

LobbySelectScreen::LobbySelectScreen(ServerConnection &serverConnection, Player &self, sf::RenderTarget &window) :
        window{window},
        serverConnection{serverConnection},
        self{self},
        gui{window},
        lobbyNameEditBox{tgui::EditBox::create()},
        createLobbyButton{tgui::Button::create("Create Lobby")},
        refreshButton{tgui::Button::create("Refresh")},
        leaveLobbyButton{tgui::Button::create("Leave Lobby")},
        lobbyListBox{tgui::ListBox::create()},
        statusLabel{tgui::Label::create()},
        lobbyCaptionLabel{tgui::Label::create("Lobby:")},
        lobbyNameLabel{tgui::Label::create("TestLobby")},
        playerCaptionLabel{tgui::Label::create("Players:")},
        playerOneLabel{tgui::Label::create("PlayerOne")},
        playerTwoLabel{tgui::Label::create("PlayerTwo")},
        playButton{tgui::Button::create("PLAY")} {
    serverConnection.availableLobbiesListener.subscribe(
            std::bind(&LobbySelectScreen::onAvailableLobbies, this, std::placeholders::_1));
    serverConnection.lobbyJoinedListener.subscribe(
            std::bind(&LobbySelectScreen::onLobbyJoined, this, std::placeholders::_1));

    // Center lobbyListBox
    lobbyListBox->setSize("80%", "30%");
    lobbyListBox->setPosition((tgui::bindWidth(gui) - tgui::bindWidth(lobbyListBox)) / 2.0,
                              tgui::bindHeight(gui) / 2.0);
    lobbyListBox->connect(lobbyListBox->onDoubleClick.getName(),
                          std::bind(&LobbySelectScreen::joinLobby, this));
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

    leaveLobbyButton->setPosition(tgui::bindLeft(refreshButton) - tgui::bindWidth(refreshButton) - 20,
                                  tgui::bindTop(refreshButton));
    leaveLobbyButton->connect("pressed", std::bind(&LobbySelectScreen::leaveLobby, this));
    leaveLobbyButton->setEnabled(false);
    gui.add(leaveLobbyButton);

    statusLabel->setPosition(tgui::bindLeft(lobbyListBox),
                             tgui::bindTop(lobbyListBox) - tgui::bindHeight(statusLabel) - 20);
    gui.add(statusLabel);

    playerTwoLabel->setPosition(tgui::bindLeft(playerOneLabel),
                                tgui::bindTop(statusLabel) - tgui::bindHeight(playerTwoLabel) - 20);
    playerTwoLabel->getRenderer()->setTextColor(sf::Color::White);
    playerTwoLabel->setTextSize(30);
    gui.add(playerTwoLabel);

    playerOneLabel->setPosition(tgui::bindRight(playerCaptionLabel) + 20,
                                tgui::bindTop(playerTwoLabel) - tgui::bindHeight(playerOneLabel));
    playerOneLabel->getRenderer()->setTextColor(sf::Color::White);
    playerOneLabel->setTextSize(30);
    gui.add(playerOneLabel);

    playerCaptionLabel->setPosition(tgui::bindLeft(lobbyListBox), tgui::bindTop(playerOneLabel));
    playerCaptionLabel->getRenderer()->setTextColor(sf::Color::White);
    playerCaptionLabel->setTextSize(30);
    gui.add(playerCaptionLabel);

    lobbyCaptionLabel->setPosition(tgui::bindLeft(playerCaptionLabel),
                                   tgui::bindTop(playerCaptionLabel) - tgui::bindHeight(lobbyCaptionLabel) - 20);
    lobbyCaptionLabel->getRenderer()->setTextColor(sf::Color::White);
    lobbyCaptionLabel->setTextSize(30);
    gui.add(lobbyCaptionLabel);

    lobbyNameLabel->setPosition(tgui::bindRight(lobbyCaptionLabel) + 20, tgui::bindTop(lobbyCaptionLabel));
    lobbyNameLabel->getRenderer()->setTextColor(sf::Color::White);
    lobbyNameLabel->setTextSize(30);
    gui.add(lobbyNameLabel);

    playButton->setPosition(tgui::bindRight(lobbyListBox) - tgui::bindWidth(playButton),
                            tgui::bindTop(lobbyListBox) - tgui::bindHeight(playButton) - 20);
    playButton->setSize(100, 100);
    playButton->setEnabled(false);
    gui.add(playButton);
}
