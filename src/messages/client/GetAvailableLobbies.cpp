//
// Created by jonas on 30.12.19.
//

#include <network/messages/client/GetAvailableLobbies.h>

void to_json(nlohmann::json &j, const GetAvailableLobbies &g) {
    j["messageType"] = g.messageType;
    j["userId"] = g.userId;
}

void from_json(const nlohmann::json &j, GetAvailableLobbies &g) {
    j.at("messageType").get_to(g.messageType);
    j.at("userId").get_to(g.userId);
}