//
// Created by kenny on 12/10/24.
//

#ifndef GAMEPIECEGENERATOR_H
#define GAMEPIECEGENERATOR_H
#include <string>
#include <iostream>
#include "../Enemy/Enemy.h"
#include "../AbilityBook/AbilityBook.h"
#include "../Consumable/Consumable.h"
class GamePieceGenerator {
  static std::string names[30];
  static std::string epithets[30];

public:
  GamePieceGenerator();

  static Enemy* generateEnemy(int _row, int _column);
  static AbilityBook* generateAbilityBook(int _row, int _column);
  static Consumable* generateConsumable(int _row, int _column);
  // make private
  static std::string generateRandomName();
  static Ability* generateAbility();
};



#endif //GAMEPIECEGENERATOR_H
