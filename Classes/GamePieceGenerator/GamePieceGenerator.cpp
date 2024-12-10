//
// Created by kenny on 12/10/24.
//

#include "GamePieceGenerator.h"

std::string GamePieceGenerator::names[30] = {
    "Gorlock", "Zarvok", "Dranath", "Vorgrim", "Kralgor",
    "Thalvorn", "Morvok", "Gravok", "Tarnok", "Vraxor",
    "Zulthar", "Dromar", "Kragnar", "Malvok", "Brazok",
    "Drakthar", "Thorgal", "Grondar", "Zaroth", "Volgar",
    "Krallok", "Xarvath", "Dralgar", "Narkath", "Groznar",
    "Vorthal", "Tralgor", "Graxor", "Thravok", "Zarvog"
};
std::string GamePieceGenerator::epithets[30] = {
    "Destroyer of Worlds", "The Unyielding", "The Crimson Blade", "The Silent Death",
    "The Iron Fist", "The Scourge of God", "The Eternal Flame", "The Dark One",
    "The Forsaken", "The Ravager", "The Undying", "The Cursed", "The Warlord",
    "The Chaos Bringer", "The Shadow Hunter", "The Bloodthirsty", "The Dreadlord",
    "The Obliterator", "The Doomcaller", "The Beastmaster", "The Soul Reaper",
    "The Bonecrusher", "The Flamecaller", "The Frostborn", "The Stormbringer",
    "The Nightfall", "The Ironhide", "The Lifetaker", "The Kingslayer", "The Deathdealer"
};
GamePieceGenerator::GamePieceGenerator() {}

Enemy* GamePieceGenerator::generateEnemy(int _row, int _column) {
    std::string enemyName = generateRandomName();
    Enemy* enemy = new Enemy(_row,_column, enemyName, (20 * (rand() % 6)));
    return enemy;
}

std::string GamePieceGenerator::generateRandomName() {
  std::string name = names[rand() % 30];
  std::string epithet = epithets[rand() % 30];
  return name + " " + epithet;
}