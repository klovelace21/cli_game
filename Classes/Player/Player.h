//
// Created by kenny on 12/6/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../AbstractClasses/Character/Character.h"
class Player : public Character {

public:
  Player(const std::string &_name, int _maxHealthPoints);
  Player(int _row, int _column, const std::string &_name, int _maxHealthPoints);

  void takeDamage(int damage) override;
  void restoreHealthPoints(int toRestore) override;
  void changeRow(int changeBy);
  void changeColumn(int changeBy);
};



#endif //PLAYER_H
