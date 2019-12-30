//
// Created by jonas on 30.12.19.
//

#ifndef HEXXAGON_GRAPHICSUTIL_H
#define HEXXAGON_GRAPHICSUTIL_H


#include <SFML/Graphics/Text.hpp>

namespace util {
    class GraphicsUtil {
    public:
        static void setOriginToCenter(sf::Text &object);
    };
}

#endif //HEXXAGON_GRAPHICSUTIL_H
