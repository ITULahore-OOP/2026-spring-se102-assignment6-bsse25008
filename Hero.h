#ifndef HERO_H
#define HERO_H

#include <string>
using namespace std;

// Base class representing a generic hero
class Hero {
private:
    string name;    // Hero's name
    int health;     // Current health
    int basePower;  // Base attack power

public:
    // Constructor to initialize hero's stats
    Hero(const string& name, int health, int power);

    // Destructor 
    ~Hero() = default;

    // Getter functions
    string getName() const;
    int getHealth() const;
    int getPower() const;

    // Take damage
    void takeDamage(int damage);

    // Operator overloading
    bool operator>(const Hero &other) const; // Compare power
    int operator+(const Hero &other) const;  // Combine health
};

#endif