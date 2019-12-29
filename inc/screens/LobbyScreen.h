//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_LOBBYSCREEN_H
#define HEXXAGON_LOBBYSCREEN_H


#include "Screen.h"

class LobbyScreen : public Screen {
public:
    ProgramState render(sf::RenderTarget &window) const override;

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;
};


#endif //HEXXAGON_LOBBYSCREEN_H
