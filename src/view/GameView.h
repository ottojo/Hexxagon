/**
 * @file GameView.h
 * @author jonas
 * @date 12/8/19
 * GameView holds a Board and can draw it to a sf::RenderTarget
 * It also allows highlighting of one Tile and optionally it's free neighbours
 */

#ifndef HEXXAGON_GAMEVIEW_H
#define HEXXAGON_GAMEVIEW_H


#include "screens/Screen.h"
#include "model/Board.h"
#include "util/HexGridTools.h"

// TODO: extend drawable, transformable to better integrate with SFML

class GameView {
public:
    void render(sf::RenderTarget &window) const;

    AxialCoordinate getCurrentCoordinate(sf::RenderTarget &window, sf::Vector2f location) const;

    [[nodiscard]] const Board &getBoard() const;

    void setBoard(const Board &setBoard);

    void select(int tileIndex);

    void deselect();

    [[nodiscard]] bool isShowNeighbours() const;

    void setShowNeighbours(bool newShowNeighbours);

private:
    Board board;

    void drawHex(sf::RenderTarget &window, float centerX, float centerY, sf::Transform boardTransform,
                 sf::Color fillColor, sf::Color outlineColor) const;

    sf::Vector2f boardScaling = {1, 1};

    float radius = 50;

    bool showNeighbours = true;

    std::optional<int> selectedTile;
};


#endif //HEXXAGON_GAMEVIEW_H
