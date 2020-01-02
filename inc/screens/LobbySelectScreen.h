//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_LOBBYSELECTSCREEN_H
#define HEXXAGON_LOBBYSELECTSCREEN_H


#include <Lobby.h>
#include <network/messages/server/AvailableLobbies.h>
#include <ServerConnection.h>
#include <view/TextBox.h>
#include <view/Button.h>
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

    std::vector<Lobby> lobbies;

    tgui::Gui gui;

    tgui::TextBox::Ptr lobbyNameTextBox;

    tgui::Button::Ptr createLobbyButton;

    tgui::Button::Ptr refreshButton;

    void onAvailableLobbies(const AvailableLobbies& availableLobbies);

    void newLobby();
};


#endif //HEXXAGON_LOBBYSELECTSCREEN_H
