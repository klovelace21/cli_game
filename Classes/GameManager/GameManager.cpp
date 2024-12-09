//
// Created by kenny on 12/9/24.
//

#include "GameManager.h"
bool winnerExists(Character* c1, Character* c2);
void attack(Character* attacker, Character* target);
void printBoard(Player* player);
void promptPlayerChoice(Player* player);
GameManager::GameManager() {}

void GameManager::startTurn(Player* player) {
  promptPlayerChoice(player);
}

Character* GameManager::handleBattle(Character* c1, Character* c2) {
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

bool winnerExists(Character* c1, Character* c2) {
  if (c1->getCurrentHealthPoints() > 0 && c2->getCurrentHealthPoints() > 0)
    return false;
  return true;
}

void attack(Character* attacker, Character* target) {
  Ability* abilityToUse = attacker->getAbility(attacker->chooseAbility());
  target->takeDamage(abilityToUse->getDamage());
}

void printBoard(Player* player) {
  for(int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (i == player->getRow() && j == player->getColumn()) {
        cout << " X ";
        continue;
      }
      cout << " \u2713 ";
    }
    cout << endl;
  }
}

void promptPlayerChoice(Player* player) {
  cout << "What would you like to do?" << endl;
  cout << "1. Move" << "       " << "2. Use Ability" << endl;
  cout << "3. Use Item" << "   " << "4. Print Board" << endl;
  int choice;
  cin >> choice;
  switch (choice) {
    case 1:
      cout << "You move" << endl;
    break;
    case 2:
      cout << "Use Ability" << endl;
    break;
    case 3:
      cout << "Use Item" << endl;
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