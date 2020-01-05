//
// Created by jonas on 05.01.20.
//

#include <stdexcept>
#include "TileEnumUtil.h"

int util::TileEnumUtil::enumToInt(std::string s) {
    auto underscoreIndex = s.find('_');
    if (underscoreIndex == std::string::npos) {
        throw std::invalid_argument("Could not parse tile enum \"" + s + "\" (no underscore found)");
    }
    auto numberString = s.substr(underscoreIndex);
    return std::stoi(s);
}
