/**
 * @file HexGridTools.cpp
 * @author jonas
 * @date 12/18/19
 */

#include "util/HexGridTools.h"
#include <cmath>

const CartCoordinate HexGridTools::q_base{3.0f / 2.0f, std::sqrt(3.0f) / 2.0f};
const CartCoordinate HexGridTools::r_base{0, std::sqrt(3.0f)};

CartCoordinate HexGridTools::cartesianFromAxial(AxialCoordinate coord) {
    auto x = q_base.x * coord.x;
    auto y = q_base.y * coord.x + r_base.y * coord.y;
    return {x, y};
}

AxialCoordinate HexGridTools::axialFromCartesian(CartCoordinate coord) {

    float q = (2.0f / 3.0f) * coord.x;
    float r = (-1.0f / 3.0f) * coord.x + (std::sqrt(3.0f) / 3.0f) * coord.y;
    float z = -q - r;

    auto rQ = std::round(q);
    auto rR = std::round(r);
    auto rZ = std::round(z);

    auto qDiff = std::abs(rQ - q);
    auto rDiff = std::abs(rR - r);
    auto zDiff = std::abs(rZ - z);

    if (qDiff > rDiff && qDiff > zDiff) {
        rQ = -rR - rZ;
    } else if (rDiff > zDiff) {
        rR = -rQ - rZ;
    }

    return AxialCoordinate(static_cast<int>(rQ), static_cast<int>(rR));
}

std::optional<AxialCoordinate> HexGridTools::axialFromIndex(int index) {
    auto foundEntry = intAxialMap.find(index);
    if (foundEntry == intAxialMap.end()) {
        return {};
    } else {
        return foundEntry->second;
    }
}

std::optional<int> HexGridTools::indexFromAxial(AxialCoordinate coordinate) {
    auto foundEntry = axialIntMap.find(coordinate);
    if (foundEntry == axialIntMap.end()) {
        return {};
    } else {
        return foundEntry->second;
    }
}

std::array<AxialCoordinate, 6> HexGridTools::neighbours(AxialCoordinate coordinate) {
    std::array<AxialCoordinate, 6> neighbors;
    for (unsigned int i = 0; i < neighbors.size(); i++) {
        neighbors.at(i) = coordinate + axialDirections.at(i);
    }
    return neighbors;
}

std::array<AxialCoordinate, 12> HexGridTools::indirectNeighbours(AxialCoordinate coordinate) {
    std::array<AxialCoordinate, 12> neighbors;
    for (unsigned int i = 0; i < neighbors.size(); i++) {
        neighbors.at(i) = coordinate + indirectAxialDirections.at(i);
    }
    return neighbors;
}

const std::array<AxialCoordinate, 6> HexGridTools::axialDirections = {
        AxialCoordinate{1, 0},
        AxialCoordinate{1, -1},
        AxialCoordinate{0, -1},
        AxialCoordinate{-1, 0},
        AxialCoordinate{-1, 1},
        AxialCoordinate{0, 1}};

const std::array<AxialCoordinate, 12> HexGridTools::indirectAxialDirections = {
        AxialCoordinate{0, -2},
        AxialCoordinate{1, -2},
        AxialCoordinate{2, -2},
        AxialCoordinate{2, -1},
        AxialCoordinate{2, 0},
        AxialCoordinate{1, 1},
        AxialCoordinate{0, 2},
        AxialCoordinate{-1, 2},
        AxialCoordinate{-2, 2},
        AxialCoordinate{-2, 1},
        AxialCoordinate{-2, 0},
        AxialCoordinate{-1, -1}};

const std::unordered_map<AxialCoordinate, int> HexGridTools::axialIntMap = {
        {{-4, 0},  1},
        {{-4, 1},  2},
        {{-4, 2},  3},
        {{-4, 3},  4},
        {{-4, 4},  5},
        {{-3, -1}, 6},
        {{-3, 0},  7},
        {{-3, 1},  8},
        {{-3, 2},  9},
        {{-3, 3},  10},
        {{-3, 4},  11},
        {{-2, -2}, 12},
        {{-2, -1}, 13},
        {{-2, 0},  14},
        {{-2, 1},  15},
        {{-2, 2},  16},
        {{-2, 3},  17},
        {{-2, 4},  18},
        {{-1, -3}, 19},
        {{-1, -2}, 20},
        {{-1, -1}, 21},
        {{-1, 0},  22},
        {{-1, 1},  23},
        {{-1, 2},  24},
        {{-1, 3},  25},
        {{-1, 4},  26},
        {{0,  -4}, 27},
        {{0,  -3}, 28},
        {{0,  -2}, 29},
        {{0,  -1}, 30},
        {{0,  0},  31},
        {{0,  1},  32},
        {{0,  2},  33},
        {{0,  3},  34},
        {{0,  4},  35},
        {{1,  -4}, 36},
        {{1,  -3}, 37},
        {{1,  -2}, 38},
        {{1,  -1}, 39},
        {{1,  0},  40},
        {{1,  1},  41},
        {{1,  2},  42},
        {{1,  3},  43},
        {{2,  -4}, 44},
        {{2,  -3}, 45},
        {{2,  -2}, 46},
        {{2,  -1}, 47},
        {{2,  0},  48},
        {{2,  1},  49},
        {{2,  2},  50},
        {{3,  -4}, 51},
        {{3,  -3}, 52},
        {{3,  -2}, 53},
        {{3,  -1}, 54},
        {{3,  0},  55},
        {{3,  1},  56},
        {{4,  -4}, 57},
        {{4,  -3}, 58},
        {{4,  -2}, 59},
        {{4,  -1}, 60},
        {{4,  0},  61},
};

const std::unordered_map<int, AxialCoordinate> HexGridTools::intAxialMap = {
        {1,  {-4, 0}},
        {2,  {-4, 1}},
        {3,  {-4, 2}},
        {4,  {-4, 3}},
        {5,  {-4, 4}},
        {6,  {-3, -1}},
        {7,  {-3, 0}},
        {8,  {-3, 1}},
        {9,  {-3, 2}},
        {10, {-3, 3}},
        {11, {-3, 4}},
        {12, {-2, -2}},
        {13, {-2, -1}},
        {14, {-2, 0}},
        {15, {-2, 1}},
        {16, {-2, 2}},
        {17, {-2, 3}},
        {18, {-2, 4}},
        {19, {-1, -3}},
        {20, {-1, -2}},
        {21, {-1, -1}},
        {22, {-1, 0}},
        {23, {-1, 1}},
        {24, {-1, 2}},
        {25, {-1, 3}},
        {26, {-1, 4}},
        {27, {0,  -4}},
        {28, {0,  -3}},
        {29, {0,  -2}},
        {30, {0,  -1}},
        {31, {0,  0}},
        {32, {0,  1}},
        {33, {0,  2}},
        {34, {0,  3}},
        {35, {0,  4}},
        {36, {1,  -4}},
        {37, {1,  -3}},
        {38, {1,  -2}},
        {39, {1,  -1}},
        {40, {1,  0}},
        {41, {1,  1}},
        {42, {1,  2}},
        {43, {1,  3}},
        {44, {2,  -4}},
        {45, {2,  -3}},
        {46, {2,  -2}},
        {47, {2,  -1}},
        {48, {2,  0}},
        {49, {2,  1}},
        {50, {2,  2}},
        {51, {3,  -4}},
        {52, {3,  -3}},
        {53, {3,  -2}},
        {54, {3,  -1}},
        {55, {3,  0}},
        {56, {3,  1}},
        {57, {4,  -4}},
        {58, {4,  -3}},
        {59, {4,  -2}},
        {60, {4,  -1}},
        {61, {4,  0}},
};


