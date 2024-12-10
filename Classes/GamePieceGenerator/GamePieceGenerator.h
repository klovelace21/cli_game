//
// Created by kenny on 12/10/24.
//

#ifndef GAMEPIECEGENERATOR_H
#define GAMEPIECEGENERATOR_H
#include <string>
#include <iostream>
#include "../Enemy/Enemy.h"
class GamePieceGenerator {
  static std::string names[30];
  static std::string epithets[30];

public:
  GamePieceGenerator();

  static Enemy* generateEnemy();
  static std::string generateRandomName();
};



#endif //GAMEPIECEGENERATOR_H
