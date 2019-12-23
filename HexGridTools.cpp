/**
 * @file HexGridTools.cpp
 * @author jonas
 * @date 12/18/19
 * Description here TODO
 */

#include "HexGridTools.h"

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

AxialCoordinate HexGridTools::axialFromIndex(int index) {
    return AxialCoordinate();
}

int HexGridTools::indexFromAxial(AxialCoordinate coordinate) {
    return 0;
}
