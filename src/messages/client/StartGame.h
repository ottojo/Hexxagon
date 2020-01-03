//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_STARTGAME_H
#define HEXXAGON_STARTGAME_H


#include <UUID.h>
#include "messages/Message.h"

class StartGame : public Message {
public:
    StartGame();

    UUID userId;
    UUID lobbyId;
};

void to_json(nlohmann::json &j, const StartGame &s);

void from_json(const nlohmann::json &j, StartGame &s);

#endif //HEXXAGON_STARTGAME_H
