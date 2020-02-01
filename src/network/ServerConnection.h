//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_SERVERCONNECTION_H
#define HEXXAGON_SERVERCONNECTION_H


#include <string>
#include <SopraNetwork/WebSocketClient.hpp>
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

/**
 * Holds a websocket connection to a Hexxagon server.
 * Allows listeners to be attached for any type of Server->Client message.
 * Also handles encoding and decoding of json messages.
 */
class ServerConnection {
public:

    /**
     * Create a server connection
     * @param debug Set debug to true to enable printing all messages to stdout.
     */
    explicit ServerConnection(bool debug = false) : debug{debug} {};

    /**
     * Connects to the specified server
     */
    void connect(const std::string &url, int port);

    bool isConnected();

    /**
     * Sends any message that can be converted to nlohmann::json
     * @tparam MessageType Type of message object. Shall be convertible to nlohmann::json
     */
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
