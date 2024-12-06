//
// Created by kenny on 12/6/24.
//

#include "Player.h"

Player::Player(std::string _name, int _maxHealthPoints) {
  maxHealthPoints = _maxHealthPoints;
  currentHealthPoints = _maxHealthPoints;
  row = 0;
  column = 0;
  name = _name;
}

int Player::getCurrentHealthPoints() {
  return currentHealthPoints;
}

std::string Player::getName() {
  return name;
}

int* Player::getCurrentPosition() {
  static int curPos[] = {row, column};
  return curPos;
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