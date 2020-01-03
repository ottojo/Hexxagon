/**
 * @file GameScreen.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_GAMESCREEN_H
#define HEXXAGON_GAMESCREEN_H


#include "GameView.h"
#include "HexxagonGame.h"

class GameScreen : public Screen {
public:
    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    // TODO: return next state?
    ProgramState render(sf::RenderTarget &window) override;

    GameScreen();

    void init() override;

private:
    HexxagonGame game;
    GameView view;
};


#endif //HEXXAGON_GAMESCREEN_H
