//
// Created by kenny on 12/6/24.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../AbstractClasses/Character/Character.h"


class Enemy : public Character {
  static std::string names[30];
  static std::string epithets[30];
  static std::string generateRandomName();

public:
  Enemy(int _row, int _column, const std::string &_name, int _maxHealthPoints);
  Enemy(int _row, int _column);

  void takeDamage(int damage) override;
  void restoreHealthPoints(int toRestore) override;
  int chooseAbility() override;

};


#endif //ENEMY_H
