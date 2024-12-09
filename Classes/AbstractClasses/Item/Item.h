                //
// Created by kenny on 12/7/24.
//

#ifndef ITEM_H
#define ITEM_H
#include "../GamePiece/GamePiece.h"

class Item : public GamePiece {
protected:
    bool usableOutOfCombat;
public:
  virtual ~Item() = default;
  virtual std::string getEffect() const = 0;
  Item(int _row, int _column, const std::string &_name, bool _usableOutOfCombat);
  bool isUsableOutOfCombat() const;
};



#endif //ITEM_H
