//
// Created by kenny on 12/6/24.
//

#include "Player.h"


Player::Player(const std::string &_name, int _maxHealthPoints)
  : Character(_name, _maxHealthPoints) {}

Player::Player(int _row, int _column, const std::string &_name, int _maxHealthPoints)
  : Character(_row, _column, _name, _maxHealthPoints) {}

Item* Player::chooseItemOutOfCombat() {
  cout << "Which Item would you like to use?" << endl;
  map<int, Item*>* usable = new map<int, Item*>();
  int idxCounter = 1;
  // Add usable items to usable map
  for (int i = 0; i < items.size(); i++) {
    Item** itemPtr = &items.at(i);
    if (items.at(i)->isUsableOutOfCombat()) {
      usable->insert({idxCounter, *itemPtr});
      cout << std::to_string(idxCounter++) << ". " << items.at(i)->getName() << "   ";
      if (idxCounter % 2 != 0) {
        cout << std::endl;
      }
    }
  }
  int choice;
  cout << "\n";
  cin >> choice;
  Item* toUse = usable->at(choice);
  delete usable;
  return toUse;
}

int Player::chooseAbility() {
  cout << "Which ability would you like to use?" << endl;
  for (int i = 0; i < sizeof(abilities) / sizeof(abilities[0]); i++) {
    cout << i + 1 << ". " << abilities[0].toString() << "   ";

    if (i % 2 != 0)
      cout << std::endl;

  }

  int choice;
  cin >> choice;

  // Decrement choice by 1 to return index of ability choice
  this->checkIfValidIndex(--choice);
  return choice;

}

void Player::changeRow(int changeBy) {
  int desiredRow = row + changeBy;
  if (desiredRow < 0 || desiredRow > 9) {
    return;
  }
  row = desiredRow;
}

void Player::changeColumn(int changeBy) {
  int desiredColumn = column + changeBy;
  if (desiredColumn < 0 || desiredColumn > 9) {
    return;
  }
  column = desiredColumn;
}

/*
 * When currentHealthPoints <= 0, implement death functionality
 */
void Player::takeDamage(int damage) {
  currentHealthPoints -= damage;
}

void Player::restoreHealthPoints(int toRestore) {
  if ((currentHealthPoints + toRestore) > maxHealthPoints) {
    currentHealthPoints = maxHealthPoints;
  } else {
   currentHealthPoints += toRestore;
  }
}

void Player::addItem(Item* item) {
  items.push_back(item);
}
