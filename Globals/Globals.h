//
// Created by kenny on 12/10/24.
//

#ifndef GLOBALS_H
#define GLOBALS_H
#include <cstdlib>


namespace Globals {
    extern int BOARD_HEIGHT;
    extern int BOARD_WIDTH;
    enum Type { DAMAGE = 0, HEALING = 1, BUFF = 2};
    extern Type genRandomType();
};



#endif //GLOBALS_H
