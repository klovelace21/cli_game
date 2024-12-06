//
// Created by kenny on 12/6/24.
//

#include "Character.h"


Character::~Character() = default;
Character::Character(const std::string &_name, int _maxHealthPoints)
    : GamePiece(_name),
    maxHealthPoints(_maxHealthPoints), currentHealthPoints(_maxHealthPoints) {}