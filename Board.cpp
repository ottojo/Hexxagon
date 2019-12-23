/**
 * @file Board.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include "Board.h"

Board::Board() {

    for (auto i = 1; i <= 10; i++) {
        // TODO board initialization

        tiles.emplace(i, TileState::FREE);
    }

}

std::vector<int> Board::getNeighbors(int tile) {
    // TODO neighbor finding1
    return {tile + 1, tile-1};
}

const std::map<int, Tile> &Board::getTiles() const {
    return tiles;
}
