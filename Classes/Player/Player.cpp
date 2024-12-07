//
// Created by kenny on 12/6/24.
//

#include "Player.h"


Player::Player(const std::string &_name, int _maxHealthPoints)
  : Character(_name, _maxHealthPoints) {}

Player::Player(int _row, int _column, const std::string &_name, int _maxHealthPoints)
  : Character(_row, _column, _name, _maxHealthPoints) {}

void Player::changeRow(int rowChangeVal) {
  int desiredRow = row + rowChangeVal;
  if (desiredRow < 0 || desiredRow > 9) {
    return;
  }
  row = desiredRow;
}

void Player::changeColumn(int columnChangeVal) {
  int desiredColumn = column + columnChangeVal;
  if (desiredColumn < 0 || desiredColumn > 9) {
    return;
  }
  column = desiredColumn;
}

/*
 * When currentHealthPoints <= 0, implement death functionality
 */
void Player::takeDamage(int _damage) {
  currentHealthPoints -= _damage;
}

void Player::restoreHealthPoints(int _toRestore) {
  if ((currentHealthPoints + _toRestore) > maxHealthPoints) {
    currentHealthPoints = maxHealthPoints;
  } else {
   currentHealthPoints += _toRestore;
  }
}