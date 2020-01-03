//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_GAMESTARTED_H
#define HEXXAGON_GAMESTARTED_H


#include <UUID.h>
#include <chrono>
#include "messages/Message.h"

class GameStarted : public Message {
public:
    GameStarted();

    UUID userId;
    UUID gameId;
    // TODO chrono...
    std::chrono::time_point<std::chrono::system_clock> creationDate;
};


#endif //HEXXAGON_GAMESTARTED_H
