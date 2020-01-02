//
// Created by jonas on 30.12.19.
//

#ifndef HEXXAGON_LOBBY_H
#define HEXXAGON_LOBBY_H


#include <string>
#include <UUID.h>
#include <Player.h>
#include <chrono>
#include <nlohmann/json.hpp>

class Lobby {
public:
    UUID id;
    std::string name;

    Player player1;
    Player player2;

    std::chrono::time_point<std::chrono::system_clock> creationTime;

    bool isClosed;
};

void to_json(nlohmann::json &j, const Lobby &l);

void from_json(const nlohmann::json &j, Lobby &l);

#endif //HEXXAGON_LOBBY_H
