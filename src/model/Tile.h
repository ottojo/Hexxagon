/**
 * @file Tile.h
 * @author jonas
 * @date 12/8/19
 */

#ifndef HEXXAGON_TILE_H
#define HEXXAGON_TILE_H

#include "TileState.h"

/**
 * A Tile is part of a Board, and holds it's state.
 * A Tiles state is final, all Tiles get replaced by game update.
 */
class Tile {
public:
    explicit Tile(TileState state);

    [[nodiscard]] TileState getState() const;

private:
    const TileState state;
};

#endif //HEXXAGON_TILE_H
