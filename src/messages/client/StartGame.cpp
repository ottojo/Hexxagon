//
// Created by jonas on 30.12.19.
//

#include <messages/client/StartGame.h>

void to_json(nlohmann::json &j, const StartGame &s) {
    j["messageType"] = s.messageType;
    j["userId"] = s.userId;
    j["lobbyId"] = s.lobbyId;
}

void from_json(const nlohmann::json &j, StartGame &s) {
    j.at("messageType").get_to(s.messageType);
    j.at("userId").get_to(s.userId);
    j.at("lobbyId").get_to(s.lobbyId);
}

StartGame::StartGame() : Message(MessageType::StartGame) {}
