//
// Created by kenny on 12/7/24.
//

#include "Ability.h"

Ability::Ability() : name("Basic Attack"), effectAmount(10), type(Globals::Type::DAMAGE) {}

Ability::Ability(const Globals::Type _type, const std::string &_name, int _effectAmount)
    : name(_name), effectAmount(_effectAmount), type(_type) {}

Ability::Ability(Globals::Type _type)
    : name(abilityPool.at(_type).at(rand() % 20)), effectAmount(max(10, 5 * (rand() % 5))), type(_type) {}


std::string Ability::getName() const { return name; }

int Ability::getEffectAmount() const { return effectAmount; }

Globals::Type Ability::getType() const { return type; }

// change later
std::string Ability::toString() const {
    return getName() + ": " + std::to_string(getEffectAmount()) + " effectAmount";
}


map<Globals::Type, vector<string>> Ability::abilityPool = {
    // DAMAGE
    {Globals::DAMAGE, { "Infernal Surge", "Crimson Cascade", "Soul Rend", "Scorching Arc", "Shadow Nova",
          "Razor Tempest", "Eclipse Strike", "Hellfire Barrage", "Thunderclap Smash", "Bladed Cyclone",
          "Venomous Spikes", "Starfall Impact", "Volcanic Blast", "Frozen Lance", "Phantom Shard",
          "Chaos Wave", "Obsidian Breaker", "Bloodletting Swipe", "Electric Onslaught", "Meteor Crash" }
    },
// HEALING
{Globals::HEALING, { "Healing Light", "Restorative Touch", "Renewing Wave", "Life Blossom", "Vital Surge",
"Soothing Breeze", "Rejuvenation Pulse", "Divine Mend", "Aura of Renewal", "Sanctuary Shield",
"Graceful Restoration", "Cleansing Waters", "Radiant Embrace", "Life's Harmony", "Celestial Balm",
"Sacred Rebirth", "Essence of Vitality", "Healing Rain", "Light of Hope", "Tranquility Bloom" }
},
    // BUFF
{Globals::BUFF,{ "Strength of Titans", "Ethereal Grace", "Empowering Roar", "Shield of Valor", "Blazing Resolve",
  "Arcane Amplification", "Blessing of Fortitude", "Wrathful Ascension", "Guardian's Will", "Spiritual Uplift",
  "Fury of the Storm", "Celestial Blessing", "Mighty Surge", "Unyielding Spirit", "Wings of the Phoenix",
  "Hero's Will", "Battle Hymn", "Radiance of the Ancients", "Unstoppable Force", "Empowerment Aura" }
}
};
// change to array
