//
// Created by jonas on 30.12.19.
//

#include "Lobby.h"

void to_json(nlohmann::json &j, const Lobby &l) {
    j["lobbyId"] = l.id;
    j["lobbyName"] = l.name;
    if (l.player1.has_value()) {
        j["playerOne"] = l.player1->id;
        j["playerOneUserName"] = l.player1->name;
    }
    if (l.player2.has_value()) {
        j["playerTwo"] = l.player2->id;
        j["playerTwoUserName"] = l.player2->name;
    }
    j["isClosed"] = l.isClosed;

}

void from_json(const nlohmann::json &j, Lobby &l) {
    j.at("lobbyId").get_to(l.id);
    j.at("lobbyName").get_to(l.name);
    if (j.find("playerOne") != j.end() and j.find("playerOneUserName") != j.end()) {
        l.player1.emplace(j.at("playerOneUserName"), j.at("playerOne"));
    }
    if (j.find("playerTwo") != j.end() and j.find("playerTwoUserName") != j.end()) {
        l.player2.emplace(j.at("playerTwoUserName"), j.at("playerTwo"));

    }
    j.at("isClosed").get_to(l.isClosed);
}