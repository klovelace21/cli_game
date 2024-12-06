//
// Created by kenny on 12/6/24.
//

#include "Encounter.h"

Encounter::Encounter(const std::string &_name, int _health) {
  name = _name;
  health = _health;
}

std::string Encounter::getName() {
  return name;
}

