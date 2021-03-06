/**
 * @file Board.h
 * @author jonas
 * @date 12/8/19
 */

#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H

#include <map>
#include <nlohmann/json.hpp>
#include "Tile.h"

/**
 * Board holds all Tiles of a game including index and state
 */
class Board {
public:

    /**
     * Initializes the board with 61 free tiles
     */
    Board();

    [[nodiscard]] const std::map<int, Tile> &getTiles() const;

    friend void from_json(const nlohmann::json &j, Board &b);

private:
    std::map<int, Tile> tiles;
};


#endif //HEXXAGON_BOARD_H
