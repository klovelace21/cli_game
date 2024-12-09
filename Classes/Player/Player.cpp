//
// Created by kenny on 12/6/24.
//

#include "Player.h"


Player::Player(const std::string &_name, int _maxHealthPoints)
  : Character(_name, _maxHealthPoints) {}

Player::Player(int _row, int _column, const std::string &_name, int _maxHealthPoints)
  : Character(_row, _column, _name, _maxHealthPoints) {}

int Player::chooseAbility() {
  std::cout << "Which ability would you like to use?" << std::endl;
  for (int i = 0; i < sizeof(abilities) / sizeof(abilities[0]); i++) {
    std::cout << i + 1 << ". " << abilities[0].toString() << "   ";

    if (i % 2 != 0)
      std::cout << std::endl;

  }

  int choice;
  std::cin >> choice;

  // Decrement choice by 1 to return index of ability choice
  this->checkIfValidIndex(--choice);
  return choice;

}

void Player::changeRow(int changeBy) {
  int desiredRow = row + changeBy;
  if (desiredRow < 0 || desiredRow > 9) {
    return;
  }
  row = desiredRow;
}

void Player::changeColumn(int changeBy) {
  int desiredColumn = column + changeBy;
  if (desiredColumn < 0 || desiredColumn > 9) {
    return;
  }
  column = desiredColumn;
}

/*
 * When currentHealthPoints <= 0, implement death functionality
 */
void Player::takeDamage(int damage) {
  currentHealthPoints -= damage;
}

void Player::restoreHealthPoints(int toRestore) {
  if ((currentHealthPoints + toRestore) > maxHealthPoints) {
    currentHealthPoints = maxHealthPoints;
  } else {
   currentHealthPoints += toRestore;
  }
}

void Player::addItem(Item* item) {
  items.push_back(item);
}