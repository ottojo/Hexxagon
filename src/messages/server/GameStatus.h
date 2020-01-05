//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_GAMESTATUS_H
#define HEXXAGON_GAMESTATUS_H


#include "messages/Message.h"
#include <util/UUID.h>
#include <model/Board.h>
#include <model/TileEnum.h>
#include <chrono>

class GameStatus : public Message {
public:
    GameStatus();

    UUID userId;
    UUID gameId;
    UUID playerOne;
    UUID playerTwo;
    std::string playerOneUserName;
    std::string playerTwoUserName;
    bool playerOneLeft;
    bool playerTwoLeft;
    int playerOnePoints;
    int playerTwoPoints;
    Board board;
    int turn;
    std::optional<TileEnum> lastMoveFrom;
    std::optional<TileEnum> lastMoveTo;
    std::chrono::time_point<std::chrono::system_clock> creationDate;
    std::chrono::time_point<std::chrono::system_clock> activeDate;
    UUID activePlayer;
    bool tie;
    std::optional<UUID> winner;
    bool isClosed;
};

void from_json(const nlohmann::json &j, GameStatus &l);


#endif //HEXXAGON_GAMESTATUS_H
