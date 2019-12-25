//
// Created by jonas on 24.12.19.
//

#ifndef HEXXAGON_MENUSCREEN_H
#define HEXXAGON_MENUSCREEN_H


#include "Screen.h"

class MenuScreen: public Screen {
    ProgramState render(sf::RenderTarget &window) const override;
};


#endif //HEXXAGON_MENUSCREEN_H
