//
// Created by kenny on 12/6/24.
//

#ifndef GAMEPIECE_H
#define GAMEPIECE_H


class GamePiece {
protected:
    int row = 0;
    int column = 0;
    std::string name;
    int maxHealthPoints;
    int currentHealthPoints;

public:
    virtual ~GamePiece();
    GamePiece(const std::string &_name, int _maxHealthPoints);
};



#endif //GAMEPIECE_H


