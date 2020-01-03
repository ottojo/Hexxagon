//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_MESSAGE_H
#define HEXXAGON_MESSAGE_H

#include "MessageType.h"

class Message {
public:
    MessageType messageType;

    explicit Message(MessageType type) : messageType{type} {}

    Message() : messageType{MessageType::INVALID} {}
};


void to_json(nlohmann::json &j, const Message &m);

void from_json(const nlohmann::json &j, Message &m);

#endif //HEXXAGON_MESSAGE_H
