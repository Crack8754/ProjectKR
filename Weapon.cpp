#include "Weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon(string wName, int dmg, int cost) {
    name = wName;
    baseDamage = dmg;
    energyCost = cost;
}

Weapon::~Weapon() {}

string Weapon::getName() const { return name; }
int Weapon::getBaseDamage() const { return baseDamage; }
int Weapon::getEnergyCost() const { return energyCost; }

int Weapon::calculateDamage() { 
    return baseDamage; 
}

PhysicalWeapon::PhysicalWeapon(string wName, int dmg, int cost, double chance) 
    : Weapon(wName, dmg, cost) {
    critChance = chance;
}

PhysicalWeapon::~PhysicalWeapon() {}

int PhysicalWeapon::calculateDamage() {
    cout << " -> [Physical attack] Using " << name << "!\n";
    return baseDamage;
}

EnergyWeapon::EnergyWeapon(string wName, int dmg, int cost, int pierce) 
    : Weapon(wName, dmg, cost) {
    armorPiercing = pierce;
}

EnergyWeapon::~EnergyWeapon() {}

int EnergyWeapon::calculateDamage() {
    cout << " -> [Energy attack] Using " << name << "!\n";
    return baseDamage + armorPiercing;
}