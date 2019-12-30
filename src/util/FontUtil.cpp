//
// Created by jonas on 25.12.19.
//

#include "util/FontUtil.h"

sf::Font FontUtil::defaultFont;

const sf::Font &FontUtil::getDefaultFont() {
    return defaultFont;
}

void FontUtil::init(const std::string& font) {
    if (!defaultFont.loadFromFile(font)) {
        throw std::runtime_error("Loading font \"" + font + "\" failed");
    }
}
