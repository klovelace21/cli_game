//
// Created by kenny on 12/7/24.
//

#ifndef ABILITY_H
#define ABILITY_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "../../Globals/Globals.h"
using namespace std;
class Ability {
private:
  static map<Globals::Type, vector<string>> abilityPool;
  const Globals::Type type;
  std::string name;
  int effectAmount;
public:
  Ability();
  Ability(Globals::Type _type, const std::string &_name, int _damage);
  Ability(Globals::Type _type);

  std::string getName() const;
  std::string toString() const;
  Globals::Type getType() const;
  int getEffectAmount() const;

};



#endif //ABILITY_H
