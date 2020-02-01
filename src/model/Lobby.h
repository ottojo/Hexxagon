//
// Created by jonas on 30.12.19.
//

#ifndef HEXXAGON_LOBBY_H
#define HEXXAGON_LOBBY_H


#include <string>
#include <util/UUID.h>
#include <model/Player.h>
#include <nlohmann/json.hpp>

/**
 * Represents a game lobby that can have up to 2 players joined and can be closed.
 */
class Lobby {
public:
    UUID id;
    std::string name;

    std::optional<Player> player1;
    std::optional<Player> player2;

    bool isClosed;

    friend void to_json(nlohmann::json &j, const Lobby &l);

    friend void from_json(const nlohmann::json &j, Lobby &l);
};

#endif //HEXXAGON_LOBBY_H
