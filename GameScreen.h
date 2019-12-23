/**
 * @file GameScreen.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_GAMESCREEN_H
#define HEXXAGON_GAMESCREEN_H


#include "Screen.h"
#include "Board.h"
#include "HexGridTools.h"

class GameScreen : public Screen {
public:
    void render(sf::RenderWindow &window) const override;

    explicit GameScreen(const Board &board);

    AxialCoordinate getCurrentCoordinate(sf::RenderWindow &window, sf::Vector2f location) const;

private:
    const Board &board;

    [[nodiscard]] AxialCoordinate getTileLocation(int index) const;

    void
    drawHex(sf::RenderWindow &window, float centerX, float centerY, sf::Transform boardTransform) const;

    sf::Vector2f boardScaling;

    float radius = 50;
};


#endif //HEXXAGON_GAMESCREEN_H
