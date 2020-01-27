//
// Created by jonas on 24.12.19.
//

#ifndef HEXXAGON_MENUSCREEN_H
#define HEXXAGON_MENUSCREEN_H


#include <model/Player.h>
#include "Screen.h"
#include "network/ServerConnection.h"

class MenuScreen : public Screen {

public:

    explicit MenuScreen(ServerConnection &ServerConnection, Player &self);

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    ProgramState render(sf::RenderTarget &window) override;

    void init() override;

private:
    ServerConnection &serverConnection;

    Player &self;

    void handleWelcome(Welcome welcomeMessage);

    sf::Text lobbyText;
    sf::Text serverNameText;
    sf::Text connectText;
    sf::Text exitText;

    ProgramState nextState = ProgramState::MAIN_MENU;

};


#endif //HEXXAGON_MENUSCREEN_H
