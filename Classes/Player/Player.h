//
// Created by kenny on 12/6/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../Abstract Classes/GamePiece.h"

class Player : public GamePiece {
private:
  int currentHealthPoints;
  int maxHealthPoints;
  std::string name{};
public:
  Player(const std::string &_name, int _maxHealthPoints);
  int getCurrentHealthPoints () const;
  void takeDamage(int _damage);
  void restoreHealthPoints(int _toRestore);
  std::string getName();
  int getRow () const;
  int getColumn() const;

  void changeRow(int rowChangeVal);
  void changeColumn(int columnChangeVal);
};



#endif //PLAYER_H
