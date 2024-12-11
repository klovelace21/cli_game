//
// Created by kenny on 12/6/24.
//

#include "Character.h"



Character::Character(const std::string &_name, int _maxHealthPoints)
    : GamePiece(_name),
    maxHealthPoints(_maxHealthPoints), currentHealthPoints(_maxHealthPoints) {}

int Character::getCurrentHealthPoints() const { return currentHealthPoints; }

void Character::useAbility(int idx, Character *character) {
    checkIfValidIndex(idx);
    character->takeDamage(this->getAbility(idx)->getDamage());
}

void Character::checkIfValidIndex(int idx) const {
    if (idx < 0 || idx > 3)
        throw std::invalid_argument("Invalid Ability Index");

}

Ability* Character::getAbility(int idx) {
    this->checkIfValidIndex(idx);
    return &abilities[idx];
}

void Character::setAbility(const Ability &newAbility, int idx) {
    checkIfValidIndex(idx);
    abilities[idx] = newAbility;
}

