#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "None") {
        characterID = id;
        name = n;
        level = lvl;
        healthPoints = hp;
        weaponType = weapon;
    }

    virtual void attack() {
        cout << name << " attacks with weapon: " << weaponType << endl;
    }

    virtual void defend() {
        cout << name << " defends normally." << endl;
    }

    virtual void displayStats() {
        cout << "ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "HP: " << healthPoints << endl;
        cout << "Weapon: " << weaponType << endl;
    }

    virtual ~Character() {}
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, const string& n, int lvl, int hp, const string& weapon, int armor, int dmg)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(dmg) {}

    void attack() override {
        cout << name << " strikes with melee damage of " << meleeDamage << "!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength << endl;
        cout << "Melee Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;

public:
    Mage(int id, const string& n, int lvl, int hp, const string& weapon, int mana, int spell)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}

    void defend() override {
        cout << name << " casts a magical barrier using " << manaPoints << " mana!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << endl;
        cout << "Spell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, const string& n, int lvl, int hp, const string& weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " fires arrows with accuracy " << rangedAccuracy << "!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Arrow Count: " << arrowCount << endl;
        cout << "Ranged Accuracy: " << rangedAccuracy << endl;
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;

public:
    Rogue(int id, const string& n, int lvl, int hp, const string& weapon, int stealth, int agil)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agil) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior w(1, "Thor", 10, 100, "Axe", 50, 30);
    Mage m(2, "Scarlet", 12, 80, "Staff", 100, 60);
    Archer a(3, "Legolas", 9, 90, "Bow", 20, 85);
    Rogue r(4, "Shadow", 8, 70, "Dagger", 75, 90);

    Character* characters[4] = {&w, &m, &a, &r};

    for (int i = 0; i < 4; ++i) {
        characters[i]->displayStats();
        characters[i]->attack();
        characters[i]->defend();
        cout << "----------------------------" << endl;
    }

    return 0;
}
