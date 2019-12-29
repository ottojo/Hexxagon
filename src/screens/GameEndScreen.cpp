//
// Created by jonas on 29.12.19.
//

#include "screens/GameEndScreen.h"

ProgramState GameEndScreen::render(sf::RenderTarget &window) const {
    return ProgramState::GAME_END;
}

bool GameEndScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    return false;
}
