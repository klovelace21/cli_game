//
// Created by kenny on 12/9/24.
//

#include "GameManager.h"

#include <chrono>
#include <random>
GameManager::GameManager() {}

void GameManager::startTurn(Player* player) {
  promptPlayerChoice(player);
}

Character* GameManager::handleBattle(Character* c1, Character* c2) {
  /*
   * cout Ability Type, work on Ability toString
   * cout what Ability each Character uses / how much dmg taken / given
   */
  // While there is no winner, continue battling
  while (!winnerExists(c1, c2)) {
    attack(c1, c2);
    if (c2->getCurrentHealthPoints() <= 0)
      break;
    attack(c2, c1);
  }
  // We now know a winner exists
  if (c1->getCurrentHealthPoints() <= 0)
    return c2;
  return c1;
}

void GameManager::handleItemEncounter(Player* player, Item* item) {
  cout << "Would you like to add the " << item->getName() << " to your bag?" << endl;
  cout << "Effect: " << item->getEffect() << endl;
  cout << "1. Yes" << "   " << "2. No" << endl;
  int choice;
  cin >> choice;
  cout << choice << endl;
  if (choice == 1) {
    player->addItem(item);
    return;
  }

  cout << "Item not added" << endl;
}

bool GameManager::winnerExists(const Character* c1, const Character* c2) {
  if (c1->getCurrentHealthPoints() > 0 && c2->getCurrentHealthPoints() > 0)
    return false;
  return true;
}

void GameManager::attack(Character* attacker, Character* target) {
  Ability* abilityToUse = attacker->getAbility(attacker->chooseAbility());
  target->takeDamage(abilityToUse->getEffectAmount());
}

void GameManager::printBoard(const Player* player) {
  for(int i = 0; i < Globals::BOARD_HEIGHT; i++) {
    for (int j = 0; j < Globals::BOARD_WIDTH; j++) {
      if (i == player->getRow() && j == player->getColumn()) {
        cout << " X ";
        continue;
      }
      if (visited.contains(make_tuple(i, j))) {
        cout << " \u2713 ";
      } else {
        cout << " ? ";
      }
    }
    cout << endl;
  }
}

void GameManager::promptPlayerChoice(Player* player) {
  cout << "What would you like to do?" << endl;
  cout << "1. Move" << "       " << "2. Use Ability" << endl;
  cout << "3. Use Item" << "   " << "4. Print Board" << endl;
  int choice;
  cin >> choice;
  switch (choice) {
    case 1:
      playerMove(player);
      printBoard(player);
    break;
    case 2:
      cout << "Use Ability" << endl;
    break;
    case 3:
      cout << "Use Item" << endl;
      player->chooseItemOutOfCombat();
    break;
    case 4:
      cout << "Print Board" << endl;
      printBoard(player);
      promptPlayerChoice(player);
      break;
    default:
      cout << "Invalid Choice" << endl;
      promptPlayerChoice(player);
  }
}

void GameManager::displayMoveOptions() {
  cout << "Where would you like to move?" << endl;
  cout << "Pick a direction:" << endl;
  cout << "1. Up" << "     " << "2. Down" << endl;
  cout << "3. Left" << "   " << "4. Right" << endl;
}

void GameManager::playerMove(Player* player) {
  printBoard(player);
  displayMoveOptions();
  // Move this to Player Bool: movedSuccessfully ? Or try / catch
  int choice;
  cout << "\n";
  cin >> choice;
  visited.insert(make_tuple(player->getRow(), player->getColumn()));
  switch (choice) {
    case 1:
      player->changeRow(-1);
    break;
    case 2:
      player->changeRow(1);
    break;
    case 3:
      player->changeColumn(-1);
    break;
    case 4:
      player->changeColumn(1);
    break;
    default:
      cout << "Invalid Choice" << endl;
  }
}

void GameManager::seed(Player* player, Exit* exit) {
  board[0][0] = player;
  board[exit->getRow()][exit->getColumn()] = exit;
  for (int i = 0; i < Globals::BOARD_HEIGHT; i++) {
    for (int j = 0; j < Globals::BOARD_WIDTH; j++) {
      if (i == player->getRow() && j == player->getColumn()) {
        continue;
      }
      if (i == exit->getRow() && j == exit->getColumn()) {
        continue;
      }
      Enemy* enemy = new Enemy();
      board[i][j] = enemy;
    }
  }

  for (int i = 0; i < Globals::BOARD_HEIGHT; i++) {
    for (int j = 0; j < Globals::BOARD_WIDTH; j++) {

      cout << board[i][j]->getName() << endl;

    }
  }
}

vector<GamePiece*> GameManager::seedRow(bool playerOrExit) {
  vector<GamePiece*> row;
  int toFill = playerOrExit ? Globals::BOARD_WIDTH : Globals::BOARD_WIDTH - 1;
  int idx = 0;
  while (idx < toFill - 2) {
    row.push_back(new Enemy());
    idx += 1;
  }
  row.push_back(new Consumable(Globals::genRandomType()));
  row.push_back(new AbilityBook(new Ability(Globals::genRandomType())));
  unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(row.begin(), row.end(), default_random_engine(randomSeed));
  return row;
}