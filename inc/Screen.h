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
    virtual ProgramState render(sf::RenderTarget &window) const = 0;
};


#endif //HEXXAGON_SCREEN_H
