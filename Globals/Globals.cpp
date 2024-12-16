//
// Created by kenny on 12/10/24.
//

#include "Globals.h"

namespace Globals {
    int BOARD_HEIGHT = 10;
    int BOARD_WIDTH = 10;
    // Change to accommodate buff 2 -> 3
    Type genRandomType() {
        int typeNum = rand() % 2;
        Type type;
        switch (typeNum) {
            case 0:
                type = Type::DAMAGE; break;
            case 1:
                type = Type::HEALING; break;
        }
        return type;
    }
}
