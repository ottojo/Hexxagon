/**
 * @file GameScreen.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include "screens/GameScreen.h"
#include <chrono>
#include <sstream>

bool GameScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        auto start = std::chrono::system_clock::now();
        auto click = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        auto axialTileCoordinate = view.getCurrentCoordinate(window, click);
        auto tileIndex = HexGridTools::indexFromAxial(axialTileCoordinate);
        auto end = std::chrono::system_clock::now();
        auto duration = end - start;

        if (tileIndex.has_value()) {
            std::cout << "Click on " << tileIndex.value() << " "
                      << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() << "µs" << std::endl;
            return true;
        }
    }
    return false;
}

ProgramState GameScreen::render(sf::RenderTarget &window) {
    view.render(window);
    return ProgramState::IN_GAME;
}

GameScreen::GameScreen() :
        game(),
        view(game.getBoard()) {}

void GameScreen::init() {

}
