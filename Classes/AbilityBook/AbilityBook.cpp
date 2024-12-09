//
// Created by kenny on 12/7/24.
//

#include "AbilityBook.h"
std::string craftName(Ability* toLearn) {
  return "Book of " + toLearn->getName();
}
AbilityBook::AbilityBook(int _row, int _column, Ability* _toLearn)
    : Item(_row, _column, craftName(_toLearn), true),
    toLearn(_toLearn) {}

std::string AbilityBook::getEffect() const {
    return "Learn the ability " + toLearn->getName();
}