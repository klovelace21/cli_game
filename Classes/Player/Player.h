//
// Created by kenny on 12/6/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "../AbstractClasses/Character/Character.h"
#include "../AbstractClasses/Item/Item.h"
class Player : public Character {
private:
  std::vector<Item*> items;
public:
  Player(const std::string &_name, int _maxHealthPoints);
  Player(int _row, int _column, const std::string &_name, int _maxHealthPoints);

  void takeDamage(int damage) override;
  void restoreHealthPoints(int toRestore) override;
  int chooseAbility() override;

  void changeRow(int changeBy);
  void changeColumn(int changeBy);
};



#endif //PLAYER_H
