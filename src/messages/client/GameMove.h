//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_GAMEMOVE_H
#define HEXXAGON_GAMEMOVE_H


#include <util/UUID.h>
#include "messages/Message.h"

class GameMove : public Message {
public:
    GameMove();
    UUID userId;
    UUID gameId;
    int moveFrom;
    int moveTo;
};

void to_json(nlohmann::json &j, const GameMove &c);

void from_json(const nlohmann::json &j, GameMove &c);


#endif //HEXXAGON_GAMEMOVE_H
