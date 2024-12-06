//
// Created by kenny on 12/6/24.
//

#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <string>

class GamePiece {
protected:
    int row = 0;
    int column = 0;
    std::string name;

public:
    virtual ~GamePiece();
    GamePiece();
    explicit GamePiece(const std::string &_name);
};



#endif //GAMEPIECE_H


