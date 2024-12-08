//
// Created by kenny on 12/7/24.
//

#include "Consumable.h"

Consumable::Consumable(int _row, int _column, const std::string &_name, const std::string &_buffType, int _buffAmount)
    : Item(_row, _column, _name), buffType(_buffType), buffAmount(_buffAmount) {}
