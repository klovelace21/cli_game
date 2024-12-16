//
// Created by kenny on 12/9/24.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../AbstractClasses/Character/Character.h"
#include "../Player/Player.h"
#include "../Exit/Exit.h"
#include "../Consumable/Consumable.h"
#include "../AbilityBook/AbilityBook.h"
#include "../Enemy/Enemy.h"
#include "../../Globals/Globals.h"
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
class GameManager {
private:
  inline static GamePiece* board[10][10];
  inline static set<tuple<int, int>> visited;
  // Implement usage after removing rows / cols
  inline static set<tuple<int, int>> enemies;
  inline static set<tuple<int, int>> items;

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
  static void seed(Player* player, Exit* exit);
  static vector<GamePiece*> seedRow(bool playerOrExit);
};

#endif //GAMEMANAGER_H
