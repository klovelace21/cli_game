//
// Created by kenny on 12/7/24.
//

#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include <string>
#include <vector>
#include <map>
#include "../../Globals/Globals.h"
#include "../AbstractClasses/Item/Item.h"
using namespace std;
class Consumable : public Item {
private:
 static map<Globals::Type, vector<string>> names;
 Globals::Type buffType;
 int buffAmount;
public:
  Consumable(Globals::Type _type);
  Consumable(const std::string &_name, Globals::Type _buffType, int _buffAmount);
  std::string getEffect() const override;
};



#endif //CONSUMABLE_H
