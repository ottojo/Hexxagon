//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_GETAVAILABLELOBBIES_H
#define HEXXAGON_GETAVAILABLELOBBIES_H


#include <util/UUID.h>
#include "messages/Message.h"

class GetAvailableLobbies : public Message {
public:
    GetAvailableLobbies() : Message(MessageType::GetAvailableLobbies) {}

    UUID userId;
};


void to_json(nlohmann::json &j, const GetAvailableLobbies &g);

void from_json(const nlohmann::json &j, GetAvailableLobbies &g);


#endif //HEXXAGON_GETAVAILABLELOBBIES_H
