//
// Created by kenny on 12/6/24.
//

#include "Player.h"

Player::Player(int _healthPoints) {
  healthPoints = _healthPoints;
}

int Player::getHealthPoints() {
  return healthPoints;
}