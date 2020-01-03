//
// Created by jonas on 30.12.19.
//

#ifndef HEXXAGON_PLAYER_H
#define HEXXAGON_PLAYER_H

#include <util/UUID.h>

class Player {
public:
    Player();

    Player(std::string name, UUID id);

    std::string name;
    UUID id;
};


#endif //HEXXAGON_PLAYER_H
