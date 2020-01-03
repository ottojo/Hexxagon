//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_WELCOME_H
#define HEXXAGON_WELCOME_H

#include <string>
#include "messages/Message.h"
#include <nlohmann/json.hpp>
#include <UUID.h>

class Welcome : public Message {
public:
    Welcome() : Message(MessageType::Welcome) {}

    UUID userId;
    std::string welcomeMessage;
};

void to_json(nlohmann::json &j, const Welcome &w);

void from_json(const nlohmann::json &j, Welcome &w);

#endif //HEXXAGON_WELCOME_H
