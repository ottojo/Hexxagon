/**
 * @file Screen.h
 * @author jonas
 * @date 12/8/19
 */

#ifndef HEXXAGON_SCREEN_H
#define HEXXAGON_SCREEN_H

#include <SFML/Graphics.hpp>
#include "controller/ProgramState.h"

/**
 * A Screen represents a state of the game.
 * Each Screen is responsible for input handling and drawing.
 * Only one screen will be active at any time, but the lifetime of the screen object may be much longer.
 */
class Screen {

public:
    // TODO: Refactor Screen so each screen holds reference to window for easier tgui integration
    /**
     * Each Screen must provide a render method that will be called on every frame. The Screen shall render its UI
     * into the window.
     * @param window Render target to which the screen shall render its UI
     * @return Next state of the program, if state is different to current state, currently active screen will change.
     */
    virtual ProgramState render(sf::RenderTarget &window) = 0;

    /**
     * Each Screen must provide a handleInput method that will be called for every input event while the screen is
     * visible. sf::Event::Resized events will be forwarded to each Screen, nonregarding if its visible.
     * @param event Any SFML event
     * @param window Current render target
     * @return true if event has been consumed, false otherwise
     */
    virtual bool handleInput(sf::Event event, sf::RenderTarget &window) = 0;

    /**
     * This get's called whenever the user switches from some other screen to this screen
     */
    virtual void init() = 0;
};


#endif //HEXXAGON_SCREEN_H
