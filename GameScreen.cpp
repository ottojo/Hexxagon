/**
 * @file GameScreen.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include <iostream>
#include <cmath>
#include "GameScreen.h"
#include "HexGridTools.h"

void GameScreen::render(sf::RenderWindow &window) const {
    // TODO

    float r = radius;
    float width = 2 * r;
    float height = std::sqrt(3.0f) * r;

    float hGridSpacing = width * (3.0f / 4.0f);
    float vGridSpacing = height * 0.5f;

    constexpr int gridSize = 5;
    static_assert(gridSize < 100);

    sf::Transform boardTransform = sf::Transform::Identity;

    auto[windowWidth, windowHeight] = window.getSize();
    boardTransform.translate(windowWidth * 0.5f, windowHeight * 0.5f);

    //TODO calculate scaling

    for (auto x = -gridSize * hGridSpacing; x <= gridSize * hGridSpacing; x += hGridSpacing) {
        sf::RectangleShape vertLine({1, 2 * gridSize * vGridSpacing});
        vertLine.setPosition(x, -gridSize * vGridSpacing);
        window.draw(vertLine, boardTransform);
    }

    for (auto y = -gridSize * vGridSpacing; y <= gridSize * vGridSpacing; y += vGridSpacing) {
        sf::RectangleShape horizLine({2 * gridSize * hGridSpacing, 1});
        horizLine.setPosition(-gridSize * hGridSpacing, y);
        window.draw(horizLine, boardTransform);
    }

    for (const auto &[index, tile]: board.getTiles()) {
        auto axial = HexGridTools::axialFromIndex(index);
        if (!axial.has_value()) {
            throw std::invalid_argument(
                    "Axial coordinate for tile with index " + std::to_string(index) + " not found.");
        }
        auto[x, y] = r * HexGridTools::cartesianFromAxial(axial.value());
        drawHex(window, x, y, boardTransform);
    }

    sf::CircleShape middle(5);
    middle.setPosition(0, 0);
    middle.setFillColor(sf::Color::Green);
    window.draw(middle, boardTransform);
}

void GameScreen::drawHex(sf::RenderWindow &window, float centerX, float centerY, sf::Transform boardTransform) const {
    sf::CircleShape hex(radius, 6);
    hex.setOrigin(radius, radius);
    hex.setRotation(30);
    hex.setPosition(centerX, centerY);
    hex.setOutlineThickness(1);
    hex.setOutlineColor(sf::Color::Green);
    window.draw(hex, boardTransform);
}

GameScreen::GameScreen(const Board &board) :
        board(board),
        boardScaling(1, 1) {}

AxialCoordinate GameScreen::getCurrentCoordinate(sf::RenderWindow &window, sf::Vector2f location) const {

    auto windowSize = window.getSize();

    sf::Transform hexToBoard;
    hexToBoard.translate(0.5 * windowSize.x, 0.5 * windowSize.y);
    hexToBoard.scale(boardScaling);

    auto boardToHex = hexToBoard.getInverse();

    auto cartCoord = (1 / radius) * boardToHex.transformPoint(location);

    return HexGridTools::axialFromCartesian(cartCoord);
}