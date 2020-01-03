//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_AVAILABLELOBBIES_H
#define HEXXAGON_AVAILABLELOBBIES_H


#include "messages/Message.h"
#include <util/UUID.h>
#include <model/Lobby.h>

class AvailableLobbies : public Message {
public:
    UUID userId;
    std::vector<Lobby> lobbies;
};

void to_json(nlohmann::json &j, const AvailableLobbies &a);

void from_json(const nlohmann::json &j, AvailableLobbies &a);


#endif //HEXXAGON_AVAILABLELOBBIES_H
