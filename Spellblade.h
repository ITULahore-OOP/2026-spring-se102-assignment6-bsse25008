#ifndef SPELLBLADE_H
#define SPELLBLADE_H

#include "Warrior.h"
#include "MagicalEntity.h"

// Spellblade combines Warrior and MagicalEntity
class Spellblade : public Warrior, public MagicalEntity {
public:
    Spellblade(const string& name, int health, int power, int armor, int spellPower);

    // Hybrid damage = physical + magical
    int calculateHybridDamage() const;
};

#endif