//
// Created by kenny on 12/6/24.
//

#include "Player.h"

Player::Player(int _maxHealthPoints) {
  maxHealthPoints = _maxHealthPoints;
  currentHealthPoints = _maxHealthPoints;
}

int Player::getHealthPoints() {
  return currentHealthPoints;
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