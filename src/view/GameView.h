/**
 * @file GameView.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_GAMEVIEW_H
#define HEXXAGON_GAMEVIEW_H


#include "screens/Screen.h"
#include "model/Board.h"
#include "util/HexGridTools.h"

class GameView {
public:
    void render(sf::RenderTarget &window) const;

    explicit GameView(const Board &board);

    AxialCoordinate getCurrentCoordinate(sf::RenderTarget &window, sf::Vector2f location) const;

    const Board &getBoard() const;

    void setBoard(const Board &setBoard);

    void select(int tileIndex);

    void deselect();

    bool isShowNeighbours() const;

    void setShowNeighbours(bool newShowNeighbours);

private:
    Board board;

    void drawHex(sf::RenderTarget &window, float centerX, float centerY, sf::Transform boardTransform,
                 sf::Color fillColor, sf::Color outlineColor) const;

    sf::Vector2f boardScaling;

    float radius = 50;

    bool showNeighbours;

    std::optional<int> selectedTile;
};


#endif //HEXXAGON_GAMEVIEW_H
