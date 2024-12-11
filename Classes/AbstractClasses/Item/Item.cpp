//
// Created by kenny on 12/7/24.
//

#include "Item.h"

Item::Item(const std::string &_name, bool _usableOutOfCombat)
: GamePiece(_name), usableOutOfCombat(_usableOutOfCombat) {}

bool Item::isUsableOutOfCombat() const {
    return usableOutOfCombat;
}