//
// Created by jonas on 29.12.19.
//

#include <messages/server/Welcome.h>

void to_json(nlohmann::json &j, const Welcome &w) {
    j["messageType"] = w.messageType;
    j["userId"] = w.userId;
    j["welcomeMessage"] = w.welcomeMessage;
}

void from_json(const nlohmann::json &j, Welcome &w) {
    j.at("messageType").get_to(w.messageType);
    j.at("userId").get_to(w.userId);
    j.at("welcomeMessage").get_to(w.welcomeMessage);
}
