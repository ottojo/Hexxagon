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
};


void to_json(nlohmann::json &j, const Message &m) {
    j = {{"messageType", m.messageType}};
}

void from_json(const nlohmann::json &j, Message &m) {
    j.at("messageType").get_to(m.messageType);
}

#endif //HEXXAGON_MESSAGE_H
