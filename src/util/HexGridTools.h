/**
 * @file HexGridTools.h
 * @author jonas
 * @date 12/18/19
 * Description here TODO
 */

#ifndef HEXXAGON_HEXGRIDTOOLS_H
#define HEXXAGON_HEXGRIDTOOLS_H

#include <vector>
#include <iostream>
#include <SFML/System.hpp>
#include <unordered_map>

using CartCoordinate = sf::Vector2f;

using AxialCoordinate = sf::Vector2i;

// TODO put this somewhere else
namespace std {
    template<>
    struct hash<AxialCoordinate> {
        std::size_t operator()(const AxialCoordinate &k) const {
            return std::hash<int>()(k.x) ^ (std::hash<int>()(k.y) << 1);
        }
    };
}

class HexGridTools {
public:
    /**
     * Calculate center of hexagon in cartesian coordinates
     * @param coord Hexagon in axial coordinates
     * @return center of hexagon
     */
    static CartCoordinate cartesianFromAxial(AxialCoordinate coord);

    static AxialCoordinate axialFromCartesian(CartCoordinate coord);

    static std::optional<AxialCoordinate> axialFromIndex(int index);

    static std::optional<int> indexFromAxial(AxialCoordinate coordinate);

    static std::vector<AxialCoordinate> neighbours(AxialCoordinate coordinate);

private:
    const static CartCoordinate q_base;
    const static CartCoordinate r_base;
    const static std::array<AxialCoordinate, 6> axialDirections;

    /**
     * Mapping from SoPra-Standard-Index to axial coordinate
     */
    const static std::unordered_map<int, sf::Vector2i> intAxialMap;

    /**
     * Mapping from axial coordinate to SpPra-Standard-Index
     */
    const static std::unordered_map<sf::Vector2i, int> axialIntMap;

};


#endif //HEXXAGON_HEXGRIDTOOLS_H
