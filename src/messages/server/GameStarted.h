//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_GAMESTARTED_H
#define HEXXAGON_GAMESTARTED_H


#include <util/UUID.h>
#include <chrono>
#include "messages/Message.h"

class GameStarted : public Message {
public:
    GameStarted();

    UUID userId;
    UUID gameId;
};

void to_json(nlohmann::json &j, const GameStarted &l);

void from_json(const nlohmann::json &j, GameStarted &l);


#endif //HEXXAGON_GAMESTARTED_H
