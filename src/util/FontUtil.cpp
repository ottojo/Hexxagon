//
// Created by jonas on 25.12.19.
//

#include "util/FontUtil.h"

sf::Font util::FontUtil::defaultFont;
tgui::Font util::FontUtil::tguiFont;

const sf::Font &util::FontUtil::getDefaultFont() {
    return defaultFont;
}

void util::FontUtil::init(const std::string& font) {
    if (!defaultFont.loadFromFile(font)) {
        throw std::runtime_error("Loading font \"" + font + "\" failed");
    }
    tguiFont = tgui::Font(defaultFont);
}

const tgui::Font &util::FontUtil::getTguiFont() {
    return tguiFont;
}
