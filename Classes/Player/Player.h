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
  void takeDamage(int _damage) override;
  void restoreHealthPoints(int _toRestore) override;
  void changeRow(int rowChangeVal);
  void changeColumn(int columnChangeVal);
};



#endif //PLAYER_H
