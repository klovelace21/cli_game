//
// Created by kenny on 12/7/24.
//

#include "Item.h"

Item::Item(int _row, int _column, const std::string &_name, bool _usableOutOfCombat)
: GamePiece(_row, _column, _name), usableOutOfCombat(_usableOutOfCombat) {}

bool Item::isUsableOutOfCombat() const {
    return usableOutOfCombat;
}