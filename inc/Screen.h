/**
 * @file Screen.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_SCREEN_H
#define HEXXAGON_SCREEN_H

#include <SFML/Graphics.hpp>
#include "ProgramState.h"

class Screen {

public:
    // TODO: Refactor Screen so each screen holds reference to window for easier tgui integration
    virtual ProgramState render(sf::RenderTarget &window) = 0;

    virtual bool handleInput(sf::Event event, sf::RenderTarget &window) = 0;

    virtual void init() = 0;
};


#endif //HEXXAGON_SCREEN_H
