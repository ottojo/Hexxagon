//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_SERVERCONNECTION_H
#define HEXXAGON_SERVERCONNECTION_H


#include <string>
#include <WebSocketClient.hpp>
#include <network/messages/Message.h>

#include <network/messages/server/AvailableLobbies.h>
#include <network/messages/server/GameStarted.h>
#include <network/messages/server/GameStatus.h>
#include <network/messages/server/LobbyCreated.h>
#include <network/messages/server/LobbyJoined.h>
#include <network/messages/server/LobbyStatus.h>
#include <network/messages/server/Strike.h>
#include <network/messages/server/Welcome.h>


class ServerConnection {
public:
    void connect(const std::string &url, int port);

    bool isConnected();

    template <typename MessageType>
    void send(MessageType message) {
        if (!isConnected()) {
            throw std::runtime_error("Message can not be sent, not connected to server.");
        }

        nlohmann::json encodedMessage = message;
        webSocketClient->send(encodedMessage.dump());
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
};


#endif //HEXXAGON_SERVERCONNECTION_H
