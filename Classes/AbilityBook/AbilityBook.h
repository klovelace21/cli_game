//
// Created by kenny on 12/7/24.
//

#ifndef ABILITYBOOK_H
#define ABILITYBOOK_H

#include "../AbstractClasses/Item/Item.h"
#include "../Ability/Ability.h"

class AbilityBook : public Item {
private:
  Ability* toLearn;
public:
  AbilityBook(int _row, int _column, Ability* _toLearn);
  std::string getEffect() const override;
};



#endif //ABILITYBOOK_H
