#ifndef WARRIOR_H
#define WARRIOR_H

#include "Hero.h"

// Warrior inherits Hero and adds armor
class Warrior : public Hero {
private:
    int armorRating; // Armor bonus

public:
    Warrior(const string& name, int health, int power, int armor);

    // Effective health includes armor bonus
    int calculateEffectiveHealth() const;
};

#endif