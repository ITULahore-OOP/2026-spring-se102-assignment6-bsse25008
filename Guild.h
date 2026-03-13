#ifndef GUILD_H
#define GUILD_H

#include "Hero.h"
#include <iostream>
using namespace std;

// Guild holds heroes (up to 15)
class Guild {
private:
    string guildName;
    Hero* roster[15]; // Array of hero pointers
    int memberCount;

public:
    Guild(const string& name);
    ~Guild(); // Destructor will only print message (no delete)

    void operator+=(Hero* newHero); // Recruit hero
    void displayGuildStats() const;
    int calculateTotalGuildPower() const;

    friend ostream& operator<<(ostream& os, const Guild& g);
};

#endif