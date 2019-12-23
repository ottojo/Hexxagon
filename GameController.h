/**
 * @file GameController.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_GAMECONTROLLER_H
#define HEXXAGON_GAMECONTROLLER_H


#include "GameScreen.h"
#include "HexxagonGame.h"

class GameController {
public:
    void handleInput(sf::Event event);
private:
    GameScreen screen;
    HexxagonGame game;
};


#endif //HEXXAGON_GAMECONTROLLER_H
