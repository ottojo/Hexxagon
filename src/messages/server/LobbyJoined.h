//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_LOBBYJOINED_H
#define HEXXAGON_LOBBYJOINED_H


#include <util/UUID.h>
#include "messages/Message.h"

class LobbyJoined : public Message {

public:
    LobbyJoined() : Message(MessageType::LobbyJoined) {};
    UUID userId;
    UUID lobbyId;
    bool successfullyJoined;
};

void to_json(nlohmann::json &j, const LobbyJoined &l);


void from_json(const nlohmann::json &j, LobbyJoined &l);


#endif //HEXXAGON_LOBBYJOINED_H
