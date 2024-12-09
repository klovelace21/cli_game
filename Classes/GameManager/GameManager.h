//
// Created by kenny on 12/9/24.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../AbstractClasses/Character/Character.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
class GameManager {
public:
  GameManager();
  static Character* handleBattle(Character* c1, Character* c2);

};



#endif //GAMEMANAGER_H
