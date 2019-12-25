/**
 * @file Board.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H


#include <map>
#include "../inc/Tile.h"

class Board {
public:
    Board();

    std::vector<int> getNeighbors(int tile);

    [[nodiscard]] const std::map<int, Tile> &getTiles() const;

private:
    std::map<int, Tile> tiles;
};


#endif //HEXXAGON_BOARD_H
