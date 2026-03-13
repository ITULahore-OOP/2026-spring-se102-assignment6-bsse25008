#include "Spellblade.h"

// Constructor
Spellblade::Spellblade(const string& name, int health, int power, int armor, int sp)
    : Warrior(name, health, power, armor), MagicalEntity(name, health, power, sp) {}

// Hybrid damage calculation
int Spellblade::calculateHybridDamage() const {
    return Warrior::getPower() + MagicalEntity::getSpellPower();
}