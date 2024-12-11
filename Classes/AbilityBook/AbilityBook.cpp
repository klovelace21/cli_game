//
// Created by kenny on 12/7/24.
//

#include "AbilityBook.h"
std::string craftName(Ability* toLearn) {
  return "Book of " + toLearn->getName();
}
AbilityBook::AbilityBook(Ability* _toLearn)
    : Item(craftName(_toLearn), true),
    toLearn(_toLearn) {}

std::string AbilityBook::getEffect() const {
    return "Learn the ability " + toLearn->getName();
}