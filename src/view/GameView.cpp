/**
 * @file GameView.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include <iostream>
#include <cmath>
#include "view/GameView.h"
#include "util/HexGridTools.h"

void GameView::render(sf::RenderTarget &window) const {
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

        sf::Color tileColor;
        switch (tile.getState()) {
            case TileState::FREE:
                tileColor = sf::Color::White;
                break;
            case TileState::PLAYERONE:
                tileColor = sf::Color::Blue;
                break;
            case TileState::PLAYERTWO:
                tileColor = sf::Color::Red;
                break;
            case TileState::BLOCKED:
                tileColor = sf::Color::Black;
                break;
        }

        drawHex(window, x, y, boardTransform, tileColor);
    }
}

void GameView::drawHex(sf::RenderTarget &window, float centerX, float centerY, sf::Transform boardTransform,
                       sf::Color color) const {
    sf::CircleShape hex(radius, 6);
    hex.setOrigin(radius, radius);
    hex.setRotation(30);
    hex.setPosition(centerX, centerY);
    hex.setOutlineThickness(1);
    hex.setOutlineColor(sf::Color::Green);
    hex.setFillColor(color);
    window.draw(hex, boardTransform);
}

GameView::GameView(const Board &board) :
        board(board),
        boardScaling(1, 1) {}

AxialCoordinate GameView::getCurrentCoordinate(sf::RenderTarget &window, sf::Vector2f location) const {

    auto windowSize = window.getSize();

    sf::Transform hexToBoard;
    hexToBoard.translate(0.5 * windowSize.x, 0.5 * windowSize.y);
    hexToBoard.scale(boardScaling);

    auto boardToHex = hexToBoard.getInverse();

    auto cartCoord = (1 / radius) * boardToHex.transformPoint(location);

    return HexGridTools::axialFromCartesian(cartCoord);
}

const Board &GameView::getBoard() const {
    return board;
}

void GameView::setBoard(const Board &setBoard) {
    GameView::board = setBoard;
}
