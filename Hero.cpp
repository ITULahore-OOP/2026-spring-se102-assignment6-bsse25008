#include "Hero.h"

// Constructor
Hero::Hero(const string& n, int h, int p) : name(n), health(h), basePower(p) {}

// Getters
string Hero::getName() const { return name; }
int Hero::getHealth() const { return health; }
int Hero::getPower() const { return basePower; }

// Reduce health by damage
void Hero::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0; // Never go below 0
}

// Compare heroes by power
bool Hero::operator>(const Hero &other) const {
    return basePower > other.basePower;
}

// Combine health of two heroes
int Hero::operator+(const Hero &other) const {
    return health + other.health;
}