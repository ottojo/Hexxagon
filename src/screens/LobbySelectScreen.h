//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_LOBBYSELECTSCREEN_H
#define HEXXAGON_LOBBYSELECTSCREEN_H


#include <model/Lobby.h>
#include <messages/server/AvailableLobbies.h>
#include <network/ServerConnection.h>
#include "Screen.h"
#include <TGUI/TGUI.hpp>


class LobbySelectScreen : public Screen {
public:
    ProgramState render(sf::RenderTarget &window) override;

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    void init() override;

    explicit LobbySelectScreen(ServerConnection &serverConnection, Player &self, sf::RenderTarget &window);

private:
    sf::RenderTarget &window;

    ServerConnection &serverConnection;

    Player &self;

    std::optional<Lobby> currentLobby;

    tgui::Gui gui;

    tgui::EditBox::Ptr lobbyNameEditBox;

    tgui::Button::Ptr createLobbyButton;

    tgui::Button::Ptr refreshButton;

    tgui::Button::Ptr leaveLobbyButton;

    tgui::ListBox::Ptr lobbyListBox;

    tgui::Label::Ptr statusLabel;

    tgui::Label::Ptr lobbyCaptionLabel;
    tgui::Label::Ptr lobbyNameLabel;

    tgui::Label::Ptr playerCaptionLabel;
    tgui::Label::Ptr playerOneLabel;
    tgui::Label::Ptr playerTwoLabel;

    tgui::Button::Ptr playButton;

    tgui::EditBox::Ptr userNameEditBox;

    ProgramState nextState = ProgramState::LOBBY_SELECT;

    void onAvailableLobbies(const AvailableLobbies &availableLobbies);

    void newLobby();

    void joinLobby();

    void onLobbyJoined(const LobbyJoined &lobbyJoined);

    void onLobbyStatus(const LobbyStatus &lobbyStatus);

    void leaveLobby();

    void startGame();

    void updateSelfUserName();

    std::mutex lobbyListLock;
};


#endif //HEXXAGON_LOBBYSELECTSCREEN_H
