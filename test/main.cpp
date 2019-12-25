//
// Created by jonas on 25.12.19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
