                //
// Created by kenny on 12/7/24.
//

#ifndef ITEM_H
#define ITEM_H
#include "../GamePiece/GamePiece.h"

class Item : public GamePiece {
public:
  virtual ~Item() = default;
  Item();
  Item(int _row, int _column, const std::string &_name);

};



#endif //ITEM_H
