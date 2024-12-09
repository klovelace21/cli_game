//
// Created by kenny on 12/9/24.
//

#include "GameManager.h"
bool winnerExists(Character* c1, Character* c2);
void attack(Character* attacker, Character* target);
GameManager::GameManager() {}

Character* GameManager::handleBattle(Character* c1, Character* c2) {
  // While there is no winner, continue battling
  std::cout << "hello" << std::endl;
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
  std::cout << "Would you like to add the " << item->getName() << " to your bag?" << std::endl;
  std::cout << "Effect: " << item->getEffect() << std::endl;
  std::cout << "1. Yes" << "   " << "2. No" << std::endl;
  int choice;
  std::cin >> choice;
  std::cout << choice << std::endl;
  if (choice == 1) {
    player->addItem(item);
    return;
  }

  std::cout << "Item not added" << std::endl;
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