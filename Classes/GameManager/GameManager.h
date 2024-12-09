//
// Created by kenny on 12/9/24.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../AbstractClasses/Character/Character.h"
#include "../Player/Player.h"
using namespace std;
class GameManager {
public:
  GameManager();

  static void startTurn(Player* player);
  static Character* handleBattle(Character* c1, Character* c2);
  static void handleItemEncounter(Player* player, Item* item);
};



#endif //GAMEMANAGER_H
