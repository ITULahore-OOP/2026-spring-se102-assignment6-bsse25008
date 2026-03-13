#include <iostream>
#include <string>
#include "Hero.h"
#include "Warrior.h"
#include "Knight.h"
#include "MagicalEntity.h"
#include "Spellblade.h"
#include "Guild.h"

using namespace std;

int main() {
    string guildName;
    int numHeroes;

    // Ask the user for guild name
    cout << "Enter your Guild name: ";
    getline(cin, guildName);

    Guild g(guildName);  // Create Guild object

    cout << "How many heroes do you want to add (max 15)? ";
    cin >> numHeroes;
    cin.ignore(); // Consume leftover newline

    Hero* heroes[15]; // Keep track of allocated heroes for deletion

    for (int i = 0; i < numHeroes && i < 15; i++) {
        string type, name;
        int health, power, armor, extra;

        cout << "\nEnter Hero #" << (i + 1) 
             << " type (Hero/Warrior/Knight/Spellblade): ";
        getline(cin, type);

        cout << "Name: ";
        getline(cin, name);
        cout << "Health: ";
        cin >> health;
        cout << "Power: ";
        cin >> power;

        Hero* h = nullptr; // Pointer to the new hero

        // Create object based on type
        if (type == "Hero" || type == "hero") {
            h = new Hero(name, health, power);
        }
        else if (type == "Warrior" || type == "warrior") {
            cout << "Armor Rating: ";
            cin >> armor;
            h = new Warrior(name, health, power, armor);
        }
        else if (type == "Knight" || type == "knight") {
            cout << "Armor Rating: ";
            cin >> armor;
            cout << "Charge Bonus: ";
            cin >> extra;
            h = new Knight(name, health, power, armor, extra);
        }
        else if (type == "Spellblade" || type == "spellblade") {
            cout << "Armor Rating: ";
            cin >> armor;
            cout << "Spell Power: ";
            cin >> extra;

            // Create Spellblade
            Spellblade* s = new Spellblade(name, health, power, armor, extra);

            // --- Explicit cast to Hero* via Warrior path 
            h = static_cast<Hero*>(static_cast<Warrior*>(s));
        }
        else {
            cout << "Unknown type! Please try again.\n";
            i--;          // retry this iteration
            cin.ignore(); // consume leftover newline
            continue;
        }

        heroes[i] = h;   // Save pointer for deletion
        g += h;          // Add hero to the guild
        cin.ignore();    // consume leftover newline
    }

    // Display the guild roster
    cout << "\n--- Guild Roster ---\n";
    cout << g;

    // Display detailed guild stats
    cout << "\n--- Guild Stats ---\n";
    g.displayGuildStats();

    // Delete all allocated heroes to prevent memory leaks
    for (int i = 0; i < numHeroes && i < 15; i++)
        delete heroes[i];

    return 0;
}