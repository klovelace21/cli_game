//
// Created by kenny on 12/10/24.
//

#ifndef EXIT_H
#define EXIT_H
#include "../AbstractClasses/GamePiece/GamePiece.h"

class Exit : public GamePiece {
public:
  Exit(int _row, int _column, const std::string &_name);
};



#endif //EXIT_H