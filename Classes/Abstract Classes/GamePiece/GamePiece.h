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
    GamePiece(int _row, int _column, const std::string &_name);
    explicit GamePiece(const std::string &_name);
    int getRow() const;
    int getColumn() const;
    std::string getName() const;
};



#endif //GAMEPIECE_H


