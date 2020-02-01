//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_MESSAGE_H
#define HEXXAGON_MESSAGE_H

#include "MessageType.h"

/**
 * Represents a generic message, that only holds a message type.
 * This is intended to only be used temporarily while decoding the message, to determine it's type.
 * Every message shall successfully decode to such a message.
 */
class Message {
public:
    MessageType messageType;

    explicit Message(MessageType type) : messageType{type} {}

    Message() : messageType{MessageType::INVALID} {}
};


void to_json(nlohmann::json &j, const Message &m);

void from_json(const nlohmann::json &j, Message &m);

#endif //HEXXAGON_MESSAGE_H
