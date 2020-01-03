//
// Created by jonas on 25.12.19.
//

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "messages/server/Welcome.h"

TEST(JsonEncoding, Welcome) {
    Welcome w;
    w.userId = "Jonas";
    w.welcomeMessage = "Welcome to the Game!";
    nlohmann::json j = w;
    EXPECT_STREQ(j.dump().c_str(),
                 "{\"messageType\":\"Welcome\",\"userId\":\"Jonas\",\"welcomeMessage\":\"Welcome to the Game!\"}");
}

TEST(JsonDecoding, Welcome) {
    std::string input = R"({"messageType":"Welcome","userId":"Jonas","welcomeMessage":"Welcome to the Game!"})";
    Welcome expected;
    expected.userId = "Jonas";
    expected.welcomeMessage = "Welcome to the Game!";
    nlohmann::json j = nlohmann::json::parse(input);
    auto w = j.get<Welcome>();
    EXPECT_EQ(expected.messageType, w.messageType);
    EXPECT_EQ(expected.userId, w.userId);
    EXPECT_EQ(expected.welcomeMessage, w.welcomeMessage);
}

TEST(JsonDecoding, InvalidMessage) {
    std::string input = R"({"messageType":"Blödsinn", "bla":"printTextPosition"})";
    auto m = nlohmann::json::parse(input).get<Message>();
    EXPECT_EQ(m.messageType, MessageType::INVALID);
}