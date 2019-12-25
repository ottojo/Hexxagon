//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_WELCOME_H
#define HEXXAGON_WELCOME_H

#include <string>
#include "../Message.h"
#include <nlohmann/json.hpp>

class Welcome : public Message {
public:
    Welcome() : Message(MessageType::Welcome) {}

    std::string userId;
    std::string welcomeMessage;
};

void to_json(nlohmann::json &j, const Welcome &w) {
    j = static_cast<Message>(w);
    j["messageType"] = w.messageType;
    j["userId"] = w.userId;
    j["welcomeMessage"] = w.welcomeMessage;
}

void from_json(const nlohmann::json &j, Welcome &w) {
    j.at("messageType").get_to(w.messageType); // TODO: messagetype handling
    j.at("userId").get_to(w.userId);
    j.at("welcomeMessage").get_to(w.welcomeMessage);
}

#endif //HEXXAGON_WELCOME_H
