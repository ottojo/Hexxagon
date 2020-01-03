//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_MESSAGETYPE_H
#define HEXXAGON_MESSAGETYPE_H

#include <nlohmann/json.hpp>

enum class MessageType {
    INVALID,
    Welcome,
    GetAvailableLobbies,
    AvailableLobbies,
    CreateNewLobby,
    LobbyCreated,
    JoinLobby,
    LobbyJoined,
    LobbyStatus,
    LeaveLobby,
    StartGame,
    GameStarted,
    GameStatus,
    GameMove,
    LeaveGame,
    Strike
};

NLOHMANN_JSON_SERIALIZE_ENUM(MessageType, {
    { MessageType::INVALID, nullptr },
    { MessageType::Welcome, "Welcome" },
    { MessageType::GetAvailableLobbies, "GetAvailableLobbies" },
    { MessageType::AvailableLobbies, "AvailableLobbies" },
    { MessageType::CreateNewLobby, "CreateNewLobby" },
    { MessageType::LobbyCreated, "LobbyCreated" },
    { MessageType::JoinLobby, "JoinLobby" },
    { MessageType::LobbyJoined, "LobbyJoined" },
    { MessageType::LobbyStatus, "LobbyStatus" },
    { MessageType::LeaveLobby, "LeaveLobby" },
    { MessageType::StartGame, "StartGame" },
    { MessageType::GameStarted, "GameStarted" },
    { MessageType::GameStatus, "GameStatus" },
    { MessageType::GameMove, "GameMove" },
    { MessageType::LeaveGame, "LeaveGame" },
    { MessageType::Strike, "Strike" },
})

#endif //HEXXAGON_MESSAGETYPE_H
