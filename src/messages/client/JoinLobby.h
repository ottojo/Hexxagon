//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_JOINLOBBY_H
#define HEXXAGON_JOINLOBBY_H


#include <UUID.h>
#include "messages/Message.h"

class JoinLobby : public Message {
public:
    JoinLobby() : Message(MessageType::JoinLobby) {};
    UUID userId;
    UUID lobbyId;
    std::string userName;
};

void to_json(nlohmann::json &j, const JoinLobby &l);

void from_json(const nlohmann::json &j, JoinLobby &l);

#endif //HEXXAGON_JOINLOBBY_H
