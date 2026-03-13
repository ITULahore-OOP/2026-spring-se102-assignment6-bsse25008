#include "Guild.h"

// Constructor
Guild::Guild(const string& name) : guildName(name), memberCount(0) {
    for (int i = 0; i < 15; i++)
        roster[i] = nullptr;
}

// Destructor (no delete since no virtual allowed)
Guild::~Guild() {
    cout << "The guild " << guildName << " has been disbanded!\n";
}

// Recruit a hero
void Guild::operator+=(Hero* newHero) {
    if (memberCount < 15)
        roster[memberCount++] = newHero;
    else
        cout << "Guild is at full capacity!\n";
}

// Overload << to print guild
ostream& operator<<(ostream& os, const Guild& g) {
    os << "Guild: " << g.guildName << "\n";
    os << "Members: " << g.memberCount << "\n";
    for (int i = 0; i < g.memberCount; i++)
        os << "- " << g.roster[i]->getName() 
           << " (Power: " << g.roster[i]->getPower() << ")\n";
    return os;
}

// Display stats
void Guild::displayGuildStats() const {
    int totalPower = 0;
    for (int i = 0; i < memberCount; i++)
        totalPower += roster[i]->getPower();

    cout << "Guild Name: " << guildName << "\n";
    cout << "Total Members: " << memberCount << "/15\n";
    cout << "Total Guild Power: " << totalPower << "\n";
}

// Calculate total power
int Guild::calculateTotalGuildPower() const {
    int total = 0;
    for (int i = 0; i < memberCount; i++)
        total += roster[i]->getPower();
    return total;
}