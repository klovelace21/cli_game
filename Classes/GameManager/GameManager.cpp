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

bool winnerExists(Character* c1, Character* c2) {
  if (c1->getCurrentHealthPoints() > 0 && c2->getCurrentHealthPoints() > 0)
    return false;
  return true;
}

void attack(Character* attacker, Character* target) {
  Ability* abilityToUse = attacker->getAbility(attacker->chooseAbility());
  target->takeDamage(abilityToUse->getDamage());
}