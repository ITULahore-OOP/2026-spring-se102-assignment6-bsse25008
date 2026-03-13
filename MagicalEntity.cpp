#include "MagicalEntity.h"

// Constructor
MagicalEntity::MagicalEntity(const string& name, int health, int power, int sp)
    : Hero(name, health, power), spellPower(sp) {}

// Getter for spell power
int MagicalEntity::getSpellPower() const {
    return spellPower;
}