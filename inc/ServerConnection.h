//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_SERVERCONNECTION_H
#define HEXXAGON_SERVERCONNECTION_H


#include <string>
#include <WebSocketClient.hpp>
#include <messages/Message.h>

#include <messages/server/AvailableLobbies.h>
#include <messages/server/GameStarted.h>
#include <messages/server/GameStatus.h>
#include <messages/server/LobbyCreated.h>
#include <messages/server/LobbyJoined.h>
#include <messages/server/LobbyStatus.h>
#include <messages/server/Strike.h>
#include <messages/server/Welcome.h>

#include <iostream>


class ServerConnection {
public:

    explicit ServerConnection(bool debug = false) : debug{debug} {};

    void connect(const std::string &url, int port);

    bool isConnected();

    template<typename MessageType>
    void send(MessageType message) {
        if (!isConnected()) {
            throw std::runtime_error("Message can not be sent, not connected to server.");
        }

        nlohmann::json encodedMessage = message;
        webSocketClient->send(encodedMessage.dump());

        if (debug) {
            std::cout << "Sent message: " << encodedMessage.dump() << std::endl;
        }
    }

    util::Listener<AvailableLobbies> availableLobbiesListener;
    util::Listener<GameStarted> gameStartedListener;
    util::Listener<GameStatus> gameStatusListener;
    util::Listener<LobbyCreated> lobbyCreatedListener;
    util::Listener<LobbyJoined> lobbyJoinedListener;
    util::Listener<LobbyStatus> lobbyStatusListener;
    util::Listener<Strike> strikeListener;
    util::Listener<Welcome> welcomeListener;

private:
    std::optional<network::WebSocketClient> webSocketClient;

    void receive(std::string message);

    bool debug;
};


#endif //HEXXAGON_SERVERCONNECTION_H
