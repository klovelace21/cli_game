//
// Created by kenny on 12/6/24.
//

#include "Player.h"


Player::Player(const std::string &_name, int _maxHealthPoints)
  : Character(_name, _maxHealthPoints)
{
  generateAbilities();
}

Player::Player(int _row, int _column, const std::string &_name, int _maxHealthPoints)
  : Character(_name, _maxHealthPoints), row(_row), column(_column)
{
  generateAbilities();
}

void Player::generateAbilities() {
  setAbility(*new Ability(Globals::Type::DAMAGE, 20),0);
  setAbility(*new Ability(Globals::Type::DAMAGE), 1);
  setAbility(*new Ability(Globals::Type::HEALING), 2);
  setAbility(*new Ability(Globals::Type::BUFF), 3);
}

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

int Player::getRow() const { return row; }
int Player::getColumn() const { return column;}

int Player::chooseAbility() {
  cout << "Which ability would you like to use?" << endl;
  for (int i = 0; i < sizeof(abilities) / sizeof(abilities[0]); i++) {
    cout << i + 1 << ". " << abilities[0]->toString() << "   ";

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
  int maxRow = Globals::BOARD_HEIGHT - 1;

  if (desiredRow < 0 || desiredRow > maxRow) {
    return;
  }
  row = desiredRow;
}

void Player::changeColumn(int changeBy) {
  int desiredColumn = column + changeBy;
  int maxColumn = Globals::BOARD_WIDTH - 1;

  if (desiredColumn < 0 || desiredColumn > maxColumn) {
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
