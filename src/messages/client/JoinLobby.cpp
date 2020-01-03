//
// Created by jonas on 30.12.19.
//

#include <messages/client/JoinLobby.h>

void to_json(nlohmann::json &j, const JoinLobby &l) {
    j["messageType"] = l.messageType;
    j["userId"] = l.userId;
    j["lobbyId"] = l.lobbyId;
    j["userName"] = l.userName;
}

void from_json(const nlohmann::json &j, JoinLobby &l) {
    j.at("messageType").get_to(l.messageType);
    j.at("userId").get_to(l.userId);
    j.at("lobbyId").get_to(l.lobbyId);
    j.at("userName").get_to(l.userName);
}