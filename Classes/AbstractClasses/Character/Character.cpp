//
// Created by kenny on 12/6/24.
//

#include "Character.h"

void checkIfValidIndex(int idx) {
    if (idx < 0 || idx > 4) {
        throw std::invalid_argument("Invalid Ability Index");
    }
}

Character::Character(const std::string &_name, int _maxHealthPoints)
    : GamePiece(_name),
    maxHealthPoints(_maxHealthPoints), currentHealthPoints(_maxHealthPoints) {}

Character::Character(int _row, int _column, const std::string &_name, int _maxHealthPoints)
    : GamePiece(_row, _column, _name),
    maxHealthPoints(_maxHealthPoints), currentHealthPoints(_maxHealthPoints) {}

int Character::getCurrentHealthPoints() const { return currentHealthPoints; }

Ability Character::getAbility(int idx) {
    checkIfValidIndex(idx);
    return abilities[idx];
}

void Character::setAbility(const Ability &newAbility, int idx) {
    checkIfValidIndex(idx);
    abilities[idx] = newAbility;
}

