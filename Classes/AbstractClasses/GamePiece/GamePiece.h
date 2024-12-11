//
// Created by kenny on 12/6/24.
//

#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <string>

class GamePiece {
protected:
    std::string name;

public:
    virtual ~GamePiece() = default;

    GamePiece();
    GamePiece(const std::string &_name);

    std::string getName() const;
};



#endif //GAMEPIECE_H


