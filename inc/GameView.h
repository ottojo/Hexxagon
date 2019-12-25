/**
 * @file GameView.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_GAMEVIEW_H
#define HEXXAGON_GAMEVIEW_H


#include "Screen.h"
#include "Board.h"
#include "HexGridTools.h"

class GameView {
public:
    void render(sf::RenderTarget &window) const;

    explicit GameView(const Board &board);

    AxialCoordinate getCurrentCoordinate(sf::RenderTarget &window, sf::Vector2f location) const;

private:
    const Board &board;

    void drawHex(sf::RenderTarget &window, float centerX, float centerY, sf::Transform boardTransform) const;

    sf::Vector2f boardScaling;

    float radius = 50;
};


#endif //HEXXAGON_GAMEVIEW_H
