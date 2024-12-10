//
// Created by kenny on 12/6/24.
//

#include "Enemy.h"

std::string Enemy::names[30] = {
  "Gorlock", "Zarvok", "Dranath", "Vorgrim", "Kralgor",
  "Thalvorn", "Morvok", "Gravok", "Tarnok", "Vraxor",
  "Zulthar", "Dromar", "Kragnar", "Malvok", "Brazok",
  "Drakthar", "Thorgal", "Grondar", "Zaroth", "Volgar",
  "Krallok", "Xarvath", "Dralgar", "Narkath", "Groznar",
  "Vorthal", "Tralgor", "Graxor", "Thravok", "Zarvog"
};

std::string Enemy::epithets[30] = {
  "Destroyer of Worlds", "The Unyielding", "The Crimson Blade", "The Silent Death",
  "The Iron Fist", "The Scourge of God", "The Eternal Flame", "The Dark One",
  "The Forsaken", "The Ravager", "The Undying", "The Cursed", "The Warlord",
  "The Chaos Bringer", "The Shadow Hunter", "The Bloodthirsty", "The Dreadlord",
  "The Obliterator", "The Doomcaller", "The Beastmaster", "The Soul Reaper",
  "The Bonecrusher", "The Flamecaller", "The Frostborn", "The Stormbringer",
  "The Nightfall", "The Ironhide", "The Lifetaker", "The Kingslayer", "The Deathdealer"
};

Enemy::Enemy(int _row, int _column, const std::string &_name, int _maxHealthPoints)
  : Character(_row, _column, _name, _maxHealthPoints) {}

Enemy::Enemy(int _row, int _column)
  : Character(_row, _column, generateRandomName(), (20 * (rand() % 6))){}

std::string Enemy::generateRandomName() {
  std::string name = names[rand() % 30];
  std::string epithet = epithets[rand() % 30];
  return name + " " + epithet;
}

void Enemy::takeDamage(int damage) {
  currentHealthPoints -= damage;
}

void Enemy::restoreHealthPoints(int toRestore) {
  if ((currentHealthPoints + toRestore) > maxHealthPoints) {
    currentHealthPoints = maxHealthPoints;
  } else {
    currentHealthPoints += toRestore;
  }
}

int Enemy::chooseAbility() {
  return rand() % 4;
}
