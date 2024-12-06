//
// Created by kenny on 12/6/24.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "../GamePiece/GamePiece.cpp"

class Character : public GamePiece {
protected:
  int maxHealthPoints;
  int currentHealthPoints;

public:
  ~Character() override;
  Character(const std::string &_name, int _maxHealthPoints);
  Character(int _row, int _column, const std::string &_name, int _maxHealthPoints);
  int getCurrentHealthPoints() const;
  virtual void takeDamage(int _damage);
  virtual void restoreHealthPoints(int _toRestore);
};



#endif //CHARACTER_H
