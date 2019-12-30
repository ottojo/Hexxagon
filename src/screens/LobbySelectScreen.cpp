//
// Created by jonas on 29.12.19.
//

#include <util/FontUtil.h>
#include "screens/LobbySelectScreen.h"

ProgramState LobbySelectScreen::render(sf::RenderTarget &window) {
    sf::Text t("LOBBY SELECT", FontUtil::getDefaultFont());
    t.setPosition(100, 100);
    window.draw(t);
    return ProgramState::LOBBY_SELECT;
}

bool LobbySelectScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    return false;
}

void LobbySelectScreen::init() {

}
