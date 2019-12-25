/**
 * @file Tile.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include "../inc/Tile.h"

TileState Tile::getState() const {
    return state;
}

void Tile::setState(TileState state) {
    Tile::state = state;
}

Tile::Tile(TileState state) : state(state) {}
