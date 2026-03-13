#ifndef MAGICALENTITY_H
#define MAGICALENTITY_H

#include "Hero.h"

// MagicalEntity can cast spells
class MagicalEntity : public Hero {
private:
    int spellPower;

public:
    MagicalEntity(const string& name, int health, int power, int sp);
    int getSpellPower() const;
};

#endif