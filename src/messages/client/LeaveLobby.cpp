//
// Created by jonas on 30.12.19.
//

#include <messages/client/LeaveLobby.h>

void to_json(nlohmann::json &j, const LeaveLobby &l) {
    j["messageType"] = l.messageType;
    j["userId"] = l.userId;
    j["lobbyId"] = l.lobbyId;
}

void from_json(const nlohmann::json &j, LeaveLobby &l) {
    j.at("messageType").get_to(l.messageType);
    j.at("userId").get_to(l.userId);
    j.at("lobbyId").get_to(l.lobbyId);
}

LeaveLobby::LeaveLobby() : Message(MessageType::LeaveLobby) {}
