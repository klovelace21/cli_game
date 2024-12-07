//
// Created by kenny on 12/6/24.
//

#include "Enemy.h"

Enemy::Enemy(int _row, int _column, const std::string &_name, int _maxHealthPoints)
  : Character(_row, _column, _name, _maxHealthPoints) {}

void Enemy::takeDamage(int _damage) {
  currentHealthPoints -= _damage;
}

void Enemy::restoreHealthPoints(int _toRestore) {
  if ((currentHealthPoints + _toRestore) > maxHealthPoints) {
    currentHealthPoints = maxHealthPoints;
  } else {
    currentHealthPoints += _toRestore;
  }
}