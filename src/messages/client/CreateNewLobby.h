//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_CREATENEWLOBBY_H
#define HEXXAGON_CREATENEWLOBBY_H


#include <UUID.h>
#include "messages/Message.h"

class CreateNewLobby : public Message {
public:
    CreateNewLobby() : Message(MessageType::CreateNewLobby) {};
    UUID userId;
    std::string lobbyName;
};

void to_json(nlohmann::json &j, const CreateNewLobby &c);

void from_json(const nlohmann::json &j, CreateNewLobby &c);

#endif //HEXXAGON_CREATENEWLOBBY_H
