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

Enemy::Enemy(const std::string &_name, int _maxHealthPoints)
  : Character(_name, _maxHealthPoints) {}

Enemy::Enemy()
  : Character(generateRandomName(), (20 * (rand() % 6))) {
  generateAbilities();

}

std::string Enemy::generateRandomName() {
  std::string name = names[rand() % 30];
  std::string epithet = epithets[rand() % 30];
  return name + " " + epithet;
}

// Give Enemy at least one healing and (buff ability) <- eventually
void Enemy::generateAbilities() {
  Ability* heal = new Ability(Globals::Type::HEALING);
  setAbility(*heal, 3);
  for (int i = 0; i < 3; i++) {
    Ability* ability = new Ability(Globals::Type::DAMAGE);
    setAbility(*ability, i);
  }
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

// If the ability chosen is HEALING, reroll if maxHP
int Enemy::chooseAbility() {
  int abilityIdx = rand() % 4;
  while (getAbility(abilityIdx)->getType() == Globals::Type::HEALING &&  currentHealthPoints >= maxHealthPoints) {
    abilityIdx = rand() % 4;
  }
  return abilityIdx;
}
