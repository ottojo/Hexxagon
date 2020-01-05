/**
 * @file Board.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include "Board.h"

Board::Board() {

    for (auto i = 1; i <= 61; i++) {
        // TODO board initialization

        tiles.emplace(i, TileState::FREE);
    }

}

std::vector<int> Board::getNeighbors(int tile) {
    // TODO neighbor finding
    return {tile + 1, tile - 1};
}

const std::map<int, Tile> &Board::getTiles() const {
    return tiles;
}

// TODO (or not, not relevant for the client)
// void to_json(nlohmann::json &j, const Board &b) {}

void from_json(const nlohmann::json &j, Board &b) {
    b.tiles.clear();
    auto tiles = j.at("tiles");
    for (int i = 1; i <= 61; i++) {
        b.tiles.emplace(i, tiles.at("TILE_" + std::to_string(i)).get<TileState>());
    }
}
