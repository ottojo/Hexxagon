/**
 * @file hexGrid.cpp
 * @author jonas
 * @date 1/31/20
 * Description here TODO
 */

#include <gtest/gtest.h>
#include <util/HexGridTools.h>

TEST(HexGridTools, indexToAxial) {
    auto indices = std::vector<int>{1, 2, 3};
    auto axial = std::vector<AxialCoordinate>{{-4, 0},
                                              {-4, 1},
                                              {-4, 2}};
    for (unsigned int i = 0; i < indices.size(); i++) {
        EXPECT_TRUE(HexGridTools::axialFromIndex(indices.at(i)).has_value());
        EXPECT_EQ(HexGridTools::axialFromIndex(indices.at(i)).value(), axial.at(i));
    }
}

TEST(HexGridTools, axialToIndex) {
    auto indices = std::vector<int>{1, 2, 3};
    auto axial = std::vector<AxialCoordinate>{{-4, 0},
                                              {-4, 1},
                                              {-4, 2}};
    for (unsigned int i = 0; i < indices.size(); i++) {
        EXPECT_TRUE(HexGridTools::indexFromAxial(axial.at(i)).has_value());
        EXPECT_EQ(HexGridTools::indexFromAxial(axial.at(i)).value(), indices.at(i));
    }
}

TEST(HexGridTools, indexAxialMapping) {
    for (int i = 1; i <= 61; i++) {
        auto axial = HexGridTools::axialFromIndex(i);
        EXPECT_TRUE(axial.has_value());
        auto reconstructedIndex = HexGridTools::indexFromAxial(axial.value());
        EXPECT_TRUE(reconstructedIndex.has_value());
        EXPECT_EQ(reconstructedIndex, i);
    }
}

TEST(HexGridTools, invalidIndices) {
    auto indices = std::vector<int>{-5, 1337, 420, 62, 0};
    for (auto i:indices) {
        EXPECT_FALSE(HexGridTools::axialFromIndex(i).has_value());
    }
}