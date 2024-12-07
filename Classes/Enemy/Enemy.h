//
// Created by kenny on 12/6/24.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../AbstractClasses/Character/Character.h"


class Enemy : public Character {
public:
  Enemy(int _row, int _column, const std::string &_name, int _maxHealthPoints);
  void takeDamage(int damage) override;
  void restoreHealthPoints(int toRestore) override;

};


#endif //ENEMY_H
