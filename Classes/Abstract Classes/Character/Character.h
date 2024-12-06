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
};



#endif //CHARACTER_H
