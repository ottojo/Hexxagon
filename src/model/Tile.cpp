/**
 * @file Tile.cpp
 * @author jonas
 * @date 12/8/19
 */

#include "Tile.h"

TileState Tile::getState() const {
    return state;
}

Tile::Tile(TileState state) : state(state) {}
