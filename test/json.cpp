//
// Created by jonas on 25.12.19.
//

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "../network/messages/server/Welcome.h"

TEST(JsonEncoding, Welcome) {
    Welcome w;
    w.userId = "Jonas";
    w.welcomeMessage = "Welcome to the Game!";
    nlohmann::json j = w;
    EXPECT_STREQ(j.dump().c_str(),
                 "{\"messageType\":\"Welcome\",\"userId\":\"Jonas\",\"welcomeMessage\":\"Welcome to the Game!\"}");
}