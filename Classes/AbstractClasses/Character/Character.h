//
// Created by kenny on 12/6/24.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "../GamePiece/GamePiece.h"

class Character : public GamePiece {
protected:
  int maxHealthPoints;
  int currentHealthPoints;

public:
  virtual ~Character() = default;
  Character(const std::string &_name, int _maxHealthPoints);
  Character(int _row, int _column, const std::string &_name, int _maxHealthPoints);
  int getCurrentHealthPoints() const;
  virtual void takeDamage(int _damage) = 0;
  virtual void restoreHealthPoints(int _toRestore) = 0;
};



#endif //CHARACTER_H
