//
// Created by jonas on 30.12.19.
//

#include <messages/server/GameStarted.h>

void to_json(nlohmann::json &j, const GameStarted &l) {
    j["messageType"] = l.messageType;
    j["userId"] = l.userId;
    j["gameId"] = l.gameId;
}

void from_json(const nlohmann::json &j, GameStarted &l) {
    j.at("messageType").get_to(l.messageType);
    j.at("userId").get_to(l.userId);
    j.at("gameId").get_to(l.gameId);
}

GameStarted::GameStarted() : Message{MessageType::GameStarted} {}
