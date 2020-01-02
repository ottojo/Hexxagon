//
// Created by jonas on 30.12.19.
//

#include "Lobby.h"

void to_json(nlohmann::json &j, const Lobby &l) {
    j["lobbyId"] = l.id;
    j["lobbyName"] = l.name;
    j["playerOne"] = l.player1.id;
    j["playerOneUserName"] = l.player1.name;
    j["playerTwo"] = l.player2.id;
    j["playerTwoUserName"] = l.player2.name;
    // TODO chrono bums
    //j["creationDate"] = l.creationTime;
    j["isClosed"] = l.isClosed;

}

void from_json(const nlohmann::json &j, Lobby &l) {
    j.at("lobbyId").get_to(l.id);
    j.at("lobbyName").get_to(l.name);
    j.at("playerOne").get_to(l.player1.id);
    j.at("playerOneUserName").get_to(l.player1.name);
    j.at("playerTwo").get_to(l.player2.id);
    j.at("playerTwoUserName").get_to(l.player2.name);
    // TODO chrono bums
    //j.at("creationDate") .get_to( l.creationTime);
    j.at("isClosed").get_to(l.isClosed);
}