//
// Created by jonas on 29.12.19.
//

#include <messages/Message.h>

void to_json(nlohmann::json &j, const Message &m) {
    j = {{"messageType", m.messageType}};
}

void from_json(const nlohmann::json &j, Message &m) {
    j.at("messageType").get_to(m.messageType);
}