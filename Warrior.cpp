#include "Warrior.h"

// Constructor
Warrior::Warrior(const string& name, int health, int power, int armor)
    : Hero(name, health, power), armorRating(armor) {}

// Effective health = base health + 2*armor
int Warrior::calculateEffectiveHealth() const {
    return getHealth() + (armorRating * 2);
}