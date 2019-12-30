//
// Created by jonas on 24.12.19.
//

#ifndef HEXXAGON_MENUSCREEN_H
#define HEXXAGON_MENUSCREEN_H


#include "Screen.h"
#include "ServerConnection.h"

class MenuScreen : public Screen {

public:

    MenuScreen(ServerConnection &ServerConnection);

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    ProgramState render(sf::RenderTarget &window) override;

private:
    ServerConnection &serverConnection;

    void handleWelcome(Welcome welcomeMessage);

};


#endif //HEXXAGON_MENUSCREEN_H
