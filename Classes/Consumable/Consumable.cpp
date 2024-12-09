//
// Created by kenny on 12/7/24.
//

#include "Consumable.h"
bool checkUsableOutOfCombat(const std::string &_buffType) {
    if (_buffType != "damage") {
        return true;
    }
    return false;
}
Consumable::Consumable(int _row, int _column, const std::string &_name, const std::string &_buffType, int _buffAmount)
    : Item(_row, _column, _name, checkUsableOutOfCombat(_buffType)),
    buffType(_buffType), buffAmount(_buffAmount) {}

std::string Consumable::getEffect() const {
    if (buffType == "heal")
        return "Heal " + std::to_string(buffAmount) + " hit points.";
    else if (buffType == "damage")
        return "Deal " + std::to_string(buffAmount) + " damage.";
}