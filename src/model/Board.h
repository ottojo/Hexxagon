/**
 * @file Board.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H


#include <map>
#include <nlohmann/json.hpp>
#include "Tile.h"

class Board {
public:
    Board();

    std::vector<int> getNeighbors(int tile);

    [[nodiscard]] const std::map<int, Tile> &getTiles() const;

    // TODO (or not, not relevant for the client)
    // friend void to_json(nlohmann::json &j, const Board &b);

    friend void from_json(const nlohmann::json &j, Board &b);

private:
    std::map<int, Tile> tiles;
};


#endif //HEXXAGON_BOARD_H
