//
// Created by kenny on 12/6/24.
//

#include "Character.h"

Character::Character(const std::string &_name, int _maxHealthPoints)
    : GamePiece(_name),
    maxHealthPoints(_maxHealthPoints), currentHealthPoints(_maxHealthPoints) {}
Character::Character(int _row, int _column, const std::string &_name, int _maxHealthPoints)
    : GamePiece(_row, _column, _name),
    maxHealthPoints(_maxHealthPoints), currentHealthPoints(_maxHealthPoints) {}

int Character::getCurrentHealthPoints() const { return currentHealthPoints; }