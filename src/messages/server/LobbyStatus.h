//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_LOBBYSTATUS_H
#define HEXXAGON_LOBBYSTATUS_H


#include <util/UUID.h>
#include <model/Lobby.h>
#include "messages/Message.h"

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
