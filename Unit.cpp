#include "Unit.h"
#include <iostream>

using namespace std;

Unit::Unit(string uName, int hp, int en) {
    name = uName;
    maxHealth = hp;
    health = hp;
    maxEnergy = en;
    energy = en;
    unitShield = NULL; 
    unitWeapon = NULL;
}

Unit::~Unit() {
    if (unitShield != NULL) {
        delete unitShield;
    }
    if (unitWeapon != NULL) {
        delete unitWeapon;
    }
}

string Unit::getName() const { return name; }
int Unit::getHealth() const { return health; }
int Unit::getEnergy() const { return energy; }

void Unit::setShield(Shield* s) { unitShield = s; }
Shield* Unit::getShield() const { return unitShield; }

void Unit::setWeapon(Weapon* w) { unitWeapon = w; }
Weapon* Unit::getWeapon() const { return unitWeapon; }

void Unit::useEnergy(int amount) {
    energy -= amount;
    if (energy < 0) energy = 0;
}

void Unit::takeDamage(int damage) {
    if (unitShield != NULL && unitShield->getCapacity() > 0) {
        int currentShield = unitShield->getCapacity();
        cout << " [DEFENSE] Unit's shield " << name << " takes partial damage (Capacity: " << currentShield << ")\n";
        
        if (damage <= currentShield) {
            unitShield->setCapacity(currentShield - damage);
            damage = 0;
        } else {
            damage -= currentShield;
            unitShield->setCapacity(0);
            cout << " [DANGER] Unit's shield " << name << " is completely destroyed!\n";
        }
    }
    
    if (damage > 0) {
        health -= damage;
        if (health < 0) health = 0;
        cout << " [DAMAGE] Unit " << name << " takes damage: " << damage << " HP: " << health << "\n";
    }
}

void Unit::updateTurn() {
    energy += 10; 
    if (energy > maxEnergy) energy = maxEnergy;
    if (unitShield != NULL) {
        unitShield->regenerate();
    }
}