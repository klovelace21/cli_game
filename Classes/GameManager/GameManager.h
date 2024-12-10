//
// Created by kenny on 12/9/24.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../AbstractClasses/Character/Character.h"
#include "../Player/Player.h"
#include "../../Globals/Globals.h"
#include <set>
using namespace std;
class GameManager {
private:
  inline static set<tuple<int, int>> visited;

public:
  GameManager();

  static void startTurn(Player* player);
  static Character* handleBattle(Character* c1, Character* c2);
  static void handleItemEncounter(Player* player, Item* item);
  static void playerMove(Player* player);
  static void printBoard(const Player* player);
  static void promptPlayerChoice(Player* player);
  static void displayMoveOptions();
  static bool winnerExists(const Character* c1, const Character* c2);
  static void attack(Character* attacker, Character* target);

};

#endif //GAMEMANAGER_H
