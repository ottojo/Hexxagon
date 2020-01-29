//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_FONTUTIL_H
#define HEXXAGON_FONTUTIL_H


#include <SFML/Graphics/Font.hpp>

namespace util {
    class FontUtil {
    public:
        const static sf::Font &getDefaultFont();

        static void init(const std::string& font = "assets/arial.ttf");

    private:
        static sf::Font defaultFont;
    };
}


#endif //HEXXAGON_FONTUTIL_H
