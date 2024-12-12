//
// Created by kenny on 12/7/24.
//

#include "Consumable.h"
bool checkUsableOutOfCombat(Globals::Type _buffType) {
    if (_buffType != 0) {
        return true;
    }
    return false;
}

Consumable::Consumable(Globals::Type _type)
    : Item(names.at(_type).at(rand() % 10),
    checkUsableOutOfCombat(_type)), buffType(_type), buffAmount(max(10, (5 * (rand() % 6)))){}


Consumable::Consumable(const std::string &_name, Globals::Type _buffType, int _buffAmount)
    : Item(_name, checkUsableOutOfCombat(_buffType)),
    buffType(_buffType), buffAmount(_buffAmount) {}

// Need to implement
string Consumable::getEffect() const {


    return "implement later";
}

map<Globals::Type, vector<string>> Consumable::names {
    {Globals::Type::DAMAGE,
        {"Soulfire Vial", "Venomous Dagger", "Frostbite Grenade",
            "Shock Burst Potion", "Shadow Bolt", "Corrosive Acid",
            "Soulfire Orb", "Holy Hand Grenade", "Void Tear",
            "Explosive Rune"}},
    {Globals::Type::HEALING,
        {"Healing Elixir", "Life Potion", "Mana Vial",
            "Rejuvenation Draught", "Spirit Infusion", "Health Salve",
            "Vitality Elixir", "Essence Potion", "Mending Draught",
            "Celestial Tear"}},
    {Globals::Type::BUFF,
            {"Rage Potion", "Power Elixir", "Might Infusion",
            "Fury Vial", "Strength Draught", "Berserker's Brew",
            "Adrenaline Shot", "Warlord's Elixir", "Savage Potion",
            "Battle Elixir"}}
};

