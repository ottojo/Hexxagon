//
// Created by jonas on 25.12.19.
//

#include "util/FontUtil.h"

sf::Font util::FontUtil::defaultFont;

const sf::Font &util::FontUtil::getDefaultFont() {
    return defaultFont;
}

void util::FontUtil::init(const std::string& font) {
    if (!defaultFont.loadFromFile(font)) {
        throw std::runtime_error("Loading font \"" + font + "\" failed");
    }
}
