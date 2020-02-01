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

    /**
     * Finds the axial coordinate in the hexagonal coordinate system of the game from a position in the window.
     * Takes the current position and scaling of the game into account.
     * @param window The window in which the game is currently displayed
     * @param location Location in the window
     * @return Axial coordinate of location, can be outside the board.
     */
    AxialCoordinate getCurrentCoordinate(sf::RenderTarget &window, sf::Vector2f location) const;

    /**
     * Get a reference to the currently used Board
     */
    [[nodiscard]] const Board &getBoard() const;

    /**
     * Update the board to display
     * @param setBoard updated Board
     */
    void setBoard(const Board &setBoard);

    /**
     * Highlight the selected tile as well as it's direct and indirect neighbours
     * @param tileIndex selected Tile
     */
    void select(int tileIndex);

    /**
     * Clear selection
     */
    void deselect();

private:
    Board board;

    void drawHex(sf::RenderTarget &window, float centerX, float centerY, sf::Transform boardTransform,
                 sf::Color fillColor, sf::Color outlineColor) const;

    sf::Vector2f boardScaling = {1, 1};

    float radius = 50;

    std::optional<int> selectedTile;
};


#endif //HEXXAGON_GAMEVIEW_H
