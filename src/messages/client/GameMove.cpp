//
// Created by jonas on 05.01.20.
//

#include <util/TileEnumUtil.h>
#include "GameMove.h"

void to_json(nlohmann::json &j, const GameMove &c) {
    j["messageType"] = c.messageType;
    j["userId"] = c.userId;
    j["gameId"] = c.gameId;
    j["moveFrom"] = util::TileEnumUtil::intToEnum(c.moveFrom);
    j["moveTo"] = util::TileEnumUtil::intToEnum(c.moveTo);
}

void from_json(const nlohmann::json &j, GameMove &c) {
    j.at("messageType").get_to(c.messageType);
    j.at("userId").get_to(c.userId);
    j.at("gameId").get_to(c.gameId);
    c.moveFrom = util::TileEnumUtil::enumToInt(j.at("moveFrom").get<std::string>());
    c.moveTo = util::TileEnumUtil::enumToInt(j.at("moveTo").get<std::string>());
}

GameMove::GameMove() : Message(MessageType::GameMove) {}
