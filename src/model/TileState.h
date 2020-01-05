/**
 * @file TileState.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_TILESTATE_H
#define HEXXAGON_TILESTATE_H

#include <nlohmann/json.hpp>

enum class TileState {
    FREE,
    PLAYERONE,
    PLAYERTWO,
    BLOCKED
};


NLOHMANN_JSON_SERIALIZE_ENUM(TileState, {
    { TileState::FREE, "FREE" },
    { TileState::PLAYERONE, "PLAYERONE" },
    { TileState::PLAYERTWO, "PLAYERTWO" },
    { TileState::BLOCKED, "BLOCKED" },
})

#endif //HEXXAGON_TILESTATE_H
