//
// Created by kenny on 12/7/24.
//

#include "Ability.h"

Ability::Ability(std::string _name, int _damage)
    : name(_name), damage(_damage) {}

int Ability::getDamage() const { return damage;}

std::string Ability::getName() const { return name; }