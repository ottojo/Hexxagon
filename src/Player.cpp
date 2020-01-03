//
// Created by jonas on 30.12.19.
//

#include "Player.h"

#include <utility>

Player::Player(std::string name, UUID id) : name{std::move(name)}, id{std::move(id)} {}

Player::Player() : name{""}, id{""} {}
