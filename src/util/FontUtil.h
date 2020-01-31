//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_FONTUTIL_H
#define HEXXAGON_FONTUTIL_H


#include <SFML/Graphics/Font.hpp>
#include <TGUI/Font.hpp>

namespace util {
    class FontUtil {
    public:
        const static sf::Font &getDefaultFont();

        static const tgui::Font &getTguiFont();

        static void init(const std::string& font = "assets/Bangers-Regular.ttf");

    private:
        static sf::Font defaultFont;
        static tgui::Font tguiFont;
    };
}


#endif //HEXXAGON_FONTUTIL_H
