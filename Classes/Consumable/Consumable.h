//
// Created by kenny on 12/7/24.
//

#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include <string>
#include "../AbstractClasses/Item/Item.h"

class Consumable : public Item {
private:
 std::string buffType;
 int buffAmount;
public:
  Consumable(int _row, int _column, const std::string &_name, const std::string &_buffType, int _buffAmount);
  std::string getEffect() const override;
};



#endif //CONSUMABLE_H
