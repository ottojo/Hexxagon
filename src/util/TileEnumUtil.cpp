//
// Created by jonas on 05.01.20.
//

#include <stdexcept>
#include "TileEnumUtil.h"

int util::TileEnumUtil::enumToInt(const std::string& s) {
    auto underscoreIndex = s.find('_');
    if (underscoreIndex == std::string::npos) {
        throw std::invalid_argument("Could not parse tile enum \"" + s + "\" (no underscore found)");
    }
    auto numberString = s.substr(underscoreIndex + 1);
    return std::stoi(numberString);
}

std::string util::TileEnumUtil::intToEnum(int i) {
    return "TILE_" + std::to_string(i);
}
