//
// Created by jonas on 29.12.19.
//

#include "screens/LobbySelectScreen.h"

ProgramState LobbySelectScreen::render(sf::RenderTarget &window) {
    return ProgramState::LOBBY_SELECT;
}

bool LobbySelectScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    return false;
}
