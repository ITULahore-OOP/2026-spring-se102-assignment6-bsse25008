#include "Knight.h"

// Constructor
Knight::Knight(const string& name, int health, int power, int armor, int charge)
    : Warrior(name, health, power, armor), chargeBonus(charge) {}

// Burst damage calculation
int Knight::calculateBurstDamage() const {
    return getPower() + chargeBonus;
}