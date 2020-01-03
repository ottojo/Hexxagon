//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_LEAVELOBBY_H
#define HEXXAGON_LEAVELOBBY_H


#include <UUID.h>
#include "messages/Message.h"

class LeaveLobby : public Message {
public:
    LeaveLobby();

    UUID userId;
    UUID lobbyId;
};

void to_json(nlohmann::json &j, const LeaveLobby &l);

void from_json(const nlohmann::json &j, LeaveLobby &l);

#endif //HEXXAGON_LEAVELOBBY_H
