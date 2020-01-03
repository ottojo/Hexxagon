//
// Created by jonas on 30.12.19.
//

#include <network/messages/server/LobbyJoined.h>

void to_json(nlohmann::json &j, const LobbyJoined &l) {
    j["messageType"] = l.messageType;
    j["userId"] = l.userId;
    j["lobbyId"] = l.lobbyId;
    j["successfullyJoined"] = l.successfullyJoined;
}

void from_json(const nlohmann::json &j, LobbyJoined &l) {
    j.at("messageType").get_to(l.messageType);
    j.at("userId").get_to(l.userId);
    j.at("lobbyId").get_to(l.lobbyId);
    j.at("successfullyJoined").get_to(l.successfullyJoined);
}