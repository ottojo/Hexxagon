//
// Created by jonas on 25.12.19.
//

#ifndef HEXXAGON_FONTUTIL_H
#define HEXXAGON_FONTUTIL_H


#include <SFML/Graphics/Font.hpp>
#include <TGUI/Font.hpp>

namespace util {

    /**
     * Utility class that holds a global instance of the default font
     */
    class FontUtil {
    public:

        const static sf::Font &getDefaultFont();

        /**
         * Returns the same font as FontUtil::getDefaultFont but converted to a tgui::Font.
         * Provided to avoid dangling references after implicitly converting sf::Font to tgui::Font
         */
        const static tgui::Font &getTguiFont();

        /*
         * Loads default font from the provided path
         */
        static void init(const std::string &font = "assets/Bangers-Regular.ttf");

    private:
        static sf::Font defaultFont;
        static tgui::Font tguiFont;
    };
}


#endif //HEXXAGON_FONTUTIL_H
