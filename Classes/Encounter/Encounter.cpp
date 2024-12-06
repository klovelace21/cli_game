//
// Created by kenny on 12/6/24.
//

#include "Encounter.h"

Encounter::Encounter(std::string _name) {
  name = _name;
}

Encounter::Encounter() {
  name = "jerry";
}

std::string Encounter::getName() {
  return name;
}

