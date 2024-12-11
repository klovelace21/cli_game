//
// Created by kenny on 12/6/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include <map>
#include "../AbstractClasses/Character/Character.h"
#include "../AbstractClasses/Item/Item.h"
using namespace std;
class Player : public Character {
private:
  int row;
  int column;
  std::vector<Item*> items;
public:
  Player(const std::string &_name, int _maxHealthPoints);
  Player(int _row, int _column, const std::string &_name, int _maxHealthPoints);

  void takeDamage(int damage) override;
  void restoreHealthPoints(int toRestore) override;
  void generateAbilities() override;
  int chooseAbility() override;

  void changeRow(int changeBy);
  void changeColumn(int changeBy);
  void addItem(Item* item);
  Item* chooseItemOutOfCombat();
  int getRow() const;
  int getColumn() const;
};



#endif //PLAYER_H
