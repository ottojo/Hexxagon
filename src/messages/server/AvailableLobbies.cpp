//
// Created by jonas on 30.12.19.
//

#include <messages/server/AvailableLobbies.h>

void to_json(nlohmann::json &j, const AvailableLobbies &a) {
    j["messageType"] = a.messageType;
    j["userId"] = a.userId;
    j["availableLobbies"] = a.lobbies;
}

void from_json(const nlohmann::json &j, AvailableLobbies &a) {
    j.at("messageType").get_to(a.messageType);
    j.at("userId").get_to(a.userId);
    j.at("availableLobbies").get_to(a.lobbies);
}