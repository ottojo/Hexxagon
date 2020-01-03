//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_LOBBYSTATUS_H
#define HEXXAGON_LOBBYSTATUS_H


#include <UUID.h>
#include <Lobby.h>
#include "network/messages/Message.h"

class LobbyStatus : public Message {
public:
    LobbyStatus();

    UUID userId;
    UUID lobbyId;
    Lobby lobby;
};

void to_json(nlohmann::json &j, const LobbyStatus &l);

void from_json(const nlohmann::json &j, LobbyStatus &l);

#endif //HEXXAGON_LOBBYSTATUS_H
