//
// Created by jonas on 29.12.19.
//

#include "screens/LobbyScreen.h"

ProgramState LobbyScreen::render(sf::RenderTarget &window) {
    return ProgramState::LOBBY;
}

bool LobbyScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    return false;
}

void LobbyScreen::init() {

}
