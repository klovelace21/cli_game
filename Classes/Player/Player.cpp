//
// Created by kenny on 12/6/24.
//

#include "Player.h"


Player::Player(const std::string &_name, int _maxHealthPoints)
  : Character(_name, _maxHealthPoints) {}

Player::Player(int _row, int _column, const std::string &_name, int _maxHealthPoints)
  : Character(_row, _column, _name, _maxHealthPoints) {}

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