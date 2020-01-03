//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_GAMEENDSCREEN_H
#define HEXXAGON_GAMEENDSCREEN_H


#include <Screen.h>

class GameEndScreen : public Screen {
public:
    ProgramState render(sf::RenderTarget &window) override;

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    void init() override;
};


#endif //HEXXAGON_GAMEENDSCREEN_H
