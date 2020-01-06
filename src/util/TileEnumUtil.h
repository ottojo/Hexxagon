//
// Created by jonas on 05.01.20.
//

#ifndef HEXXAGON_TILEENUMUTIL_H
#define HEXXAGON_TILEENUMUTIL_H

#include <string>

namespace util {
    class TileEnumUtil {
    public:
        static int enumToInt(std::string s);

        static std::string intToEnum(int i);
    };
}

#endif //HEXXAGON_TILEENUMUTIL_H
