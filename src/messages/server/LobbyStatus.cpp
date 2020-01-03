//
// Created by jonas on 30.12.19.
//

#include <network/messages/server/LobbyStatus.h>

void to_json(nlohmann::json &j, const LobbyStatus &l) {
    j["messageType"] = l.messageType;
    j["userId"] = l.userId;
    j["lobbyId"] = l.lobbyId;
    j["lobby"] = l.lobby;
}

void from_json(const nlohmann::json &j, LobbyStatus &l) {
    j.at("messageType").get_to(l.messageType);
    j.at("userId").get_to(l.userId);
    j.at("lobbyId").get_to(l.lobbyId);
    j.at("lobby").get_to(l.lobby);
}

LobbyStatus::LobbyStatus() : Message{MessageType::LobbyStatus} {}
