/**
 * @file Tile.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_TILE_H
#define HEXXAGON_TILE_H

#include <vector>
#include "TileState.h"


class Tile {
public:
    Tile(TileState state);
    TileState getState() const;

    void setState(TileState state);

private:
    TileState state;
};


#endif //HEXXAGON_TILE_H
