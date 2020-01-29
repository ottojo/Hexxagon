/**
 * @file Screen.h
 * @author jonas
 * @date 12/8/19
 * A Screen represents a state of the game.
 * Each Screen is responsible for input handling and drawing.
 * Only one screen will be active at any time, but the lifetime of the screen object may be much longer.
 */

#ifndef HEXXAGON_SCREEN_H
#define HEXXAGON_SCREEN_H

#include <SFML/Graphics.hpp>
#include "controller/ProgramState.h"

class Screen {

public:
    // TODO: Refactor Screen so each screen holds reference to window for easier tgui integration
    virtual ProgramState render(sf::RenderTarget &window) = 0;

    virtual bool handleInput(sf::Event event, sf::RenderTarget &window) = 0;

    /**
     * This get's called whenever the user switches from some other screen to this screen
     */
    virtual void init() = 0;
};


#endif //HEXXAGON_SCREEN_H
