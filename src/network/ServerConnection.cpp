//
// Created by jonas on 25.12.19.
//


#include <iostream>
#include "ServerConnection.h"

bool ServerConnection::isConnected() {
    return webSocketClient.has_value();
}

void ServerConnection::connect(const std::string &url, int port) {
    this->webSocketClient.emplace(url, "/", port, "");
    webSocketClient->receiveListener.subscribe(std::bind(&ServerConnection::receive, this, std::placeholders::_1));
}


void ServerConnection::receive(std::string message) {

    if (debug) {
        std::cout << "Recv message: " << message << std::endl;
    }

    auto json = nlohmann::json::parse(message);
    auto genericMessage = json.get<Message>();

    switch (genericMessage.messageType) {

        case MessageType::Welcome:
            welcomeListener(json.get<Welcome>());
            break;
        case MessageType::AvailableLobbies:
            availableLobbiesListener(json.get<AvailableLobbies>());
            break;
        case MessageType::LobbyCreated:
            lobbyCreatedListener(json.get<LobbyCreated>());
            break;
        case MessageType::LobbyJoined:
            lobbyJoinedListener(json.get<LobbyJoined>());
            break;
        case MessageType::LobbyStatus:
            lobbyStatusListener(json.get<LobbyStatus>());
            break;
        case MessageType::GameStarted:
            gameStartedListener(json.get<GameStarted>());
            break;
        case MessageType::GameStatus:
            gameStatusListener(json.get<GameStatus>());
            break;
        case MessageType::Strike:
            strikeListener(json.get<Strike>());
            break;
        default:
        case MessageType::INVALID:
            throw std::runtime_error("Invalid message received");
    }
}

