//
// Created by kenny on 12/6/24.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "../GamePiece/GamePiece.h"
#include "../../Ability/Ability.h"
#include <stdexcept>
class Character : public GamePiece {
protected:
  int maxHealthPoints;
  int currentHealthPoints;
  Ability abilities[4];

  void checkIfValidIndex(int idx) const;

public:
  virtual ~Character() = default;
  virtual void takeDamage(int damage) = 0;
  virtual void restoreHealthPoints(int toRestore) = 0;
  virtual int chooseAbility() = 0;

  Character(const std::string &_name, int _maxHealthPoints);
  Character(int _row, int _column, const std::string &_name, int _maxHealthPoints);

  int getCurrentHealthPoints() const;
  Ability getAbility(int idx);
  void setAbility(const Ability &newAbility, int idx);
  void useAbility(int idx, Character *character);
};



#endif //CHARACTER_H
