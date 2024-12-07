//
// Created by kenny on 12/7/24.
//

#ifndef ABILITY_H
#define ABILITY_H
#include <string>


class Ability {
private:
  std::string name;
  int damage;
public:
  Ability(std::string _name, int _damage);
  std::string getName() const;
  int getDamage() const;

};



#endif //ABILITY_H
