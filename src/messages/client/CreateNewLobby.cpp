//
// Created by jonas on 30.12.19.
//

#include <network/messages/client/CreateNewLobby.h>

void to_json(nlohmann::json &j, const CreateNewLobby &c) {
    j["messageType"] = c.messageType;
    j["userId"] = c.userId;
    j["lobbyName"] = c.lobbyName;
}

void from_json(const nlohmann::json &j, CreateNewLobby &c) {
    j.at("messageType").get_to(c.messageType);
    j.at("userId").get_to(c.userId);
    j.at("lobbyName").get_to(c.lobbyName);
}