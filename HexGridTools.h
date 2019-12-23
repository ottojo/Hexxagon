/**
 * @file HexGridTools.h
 * @author jonas
 * @date 12/18/19
 * Description here TODO
 */

#ifndef HEXXAGON_HEXGRIDTOOLS_H
#define HEXXAGON_HEXGRIDTOOLS_H

#include <tuple>
#include <vector>
#include <cmath>
#include <iostream>
#include <SFML/System.hpp>
#include "frozen/map.h"

using CartCoordinate = sf::Vector2f;

using AxialCoordinate = sf::Vector2i;

class HexGridTools {
public:
    /**
     * Calculate center of hexagon in cartesian coordinates
     * @param coord Hexagon in axial coordinates
     * @return center of hexagon
     */
    static CartCoordinate cartesianFromAxial(AxialCoordinate coord);

    static AxialCoordinate axialFromCartesian(CartCoordinate coord);

    static AxialCoordinate axialFromIndex(int index);

    static int indexFromAxial(AxialCoordinate coordinate);

private:
    const static CartCoordinate q_base;
    const static CartCoordinate r_base;

    constexpr frozen::map<int, ;,1> bla = {{1, {1, 1}}};

};


#endif //HEXXAGON_HEXGRIDTOOLS_H
