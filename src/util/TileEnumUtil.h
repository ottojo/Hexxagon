//
// Created by jonas on 05.01.20.
//

#ifndef HEXXAGON_TILEENUMUTIL_H
#define HEXXAGON_TILEENUMUTIL_H

#include <string>

namespace util {
    /**
     * Utility functions for parsing "TILE_42" style tile indices
     */
    class TileEnumUtil {
    public:
        static int enumToInt(const std::string &s);

        static std::string intToEnum(int i);
    };
}

#endif //HEXXAGON_TILEENUMUTIL_H
