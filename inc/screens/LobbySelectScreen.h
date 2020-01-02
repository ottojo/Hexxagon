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

class LobbySelectScreen : public Screen {
public:
    ProgramState render(sf::RenderTarget &window) override;

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    void init() override;

    explicit LobbySelectScreen(ServerConnection &serverConnection, Player &self);

private:
    std::vector<Lobby> lobbys;

    TextBox lobbyNameTextBox;

    ServerConnection &serverConnection;

    Player &self;

    void onAvailableLobbies(AvailableLobbies availableLobbies);

    Button refreshButton;
};


#endif //HEXXAGON_LOBBYSELECTSCREEN_H
