#ifndef KNIGHT_H
#define KNIGHT_H

#include "Warrior.h"

// Knight inherits Warrior and adds charge bonus
class Knight : public Warrior {
private:
    int chargeBonus;

public:
    Knight(const string& name, int health, int power, int armor, int charge);

    // Burst damage = base power + charge bonus
    int calculateBurstDamage() const;
};

#endif