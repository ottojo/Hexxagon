//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_LOBBYSELECTSCREEN_H
#define HEXXAGON_LOBBYSELECTSCREEN_H


#include "Screen.h"

class LobbySelectScreen: public Screen {
public:
    ProgramState render(sf::RenderTarget &window) const override;

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;
};


#endif //HEXXAGON_LOBBYSELECTSCREEN_H
