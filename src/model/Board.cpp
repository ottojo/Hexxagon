#include "Board.h"

Board::Board() {
    for (auto i = 1; i <= 61; i++) {
        tiles.emplace(i, TileState::FREE);
    }
}

const std::map<int, Tile> &Board::getTiles() const {
    return tiles;
}

void from_json(const nlohmann::json &j, Board &b) {
    b.tiles.clear();
    auto tiles = j.at("tiles");
    for (int i = 1; i <= 61; i++) {
        b.tiles.emplace(i, tiles.at("TILE_" + std::to_string(i)).get<TileState>());
    }
}
