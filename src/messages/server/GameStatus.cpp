//
// Created by jonas on 30.12.19.
//

#include <messages/server/GameStatus.h>
#include <util/OptionalSerialization.h>
#include <util/TileEnumUtil.h>

void from_json(const nlohmann::json &j, GameStatus &l) {
    j.at("messageType").get_to(l.messageType);
    j.at("userId").get_to(l.userId);
    j.at("gameId").get_to(l.gameId);
    j.at("playerOne").get_to(l.playerOne);
    j.at("playerTwo").get_to(l.playerTwo);


    j.at("playerOneUserName").get_to(l.playerOneUserName);
    j.at("playerTwoUserName").get_to(l.playerTwoUserName);
    j.at("playerOneLeft").get_to(l.playerOneLeft);
    j.at("playerTwoLeft").get_to(l.playerTwoLeft);
    j.at("playerOnePoints").get_to(l.playerOnePoints);
    j.at("playerTwoPoints").get_to(l.playerTwoPoints);
    j.at("board").get_to(l.board);
    j.at("turn").get_to(l.turn);
    if (j.find("lastMoveFrom") != j.end()) {
        l.lastMoveFrom = util::TileEnumUtil::enumToInt(j.at("lastMoveFrom").get<std::string>());
    }
    if (j.find("lastMoveTo") != j.end()) {
        l.lastMoveTo = util::TileEnumUtil::enumToInt(j.at("lastMoveTo").get<std::string>());
    }
    // j.at("creationDate").get_to(l.creationDate);
    // j.at("activeDate").get_to(l.activeDate);
    j.at("activePlayer").get_to(l.activePlayer);
    j.at("tie").get_to(l.tie);
    if (j.find("winner") != j.end()) {
        j.at("winner").get_to(l.winner);
    }
    j.at("isClosed").get_to(l.isClosed);

}

GameStatus::GameStatus() : Message{MessageType::GameStatus} {}
