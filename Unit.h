#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
#include "Shield.h"
#include "Weapon.h"

using namespace std;

class Unit {
protected:
    string name;
    int health;
    int maxHealth;
    int energy;
    int maxEnergy;
    Shield* unitShield;
    Weapon* unitWeapon;

public:
    Unit(string uName, int hp, int en);
    virtual ~Unit();

    string getName() const;
    int getHealth() const;
    int getEnergy() const;

    void setShield(Shield* s);
    Shield* getShield() const;
    
    void setWeapon(Weapon* w); 
    Weapon* getWeapon() const; 
    
    void useEnergy(int amount);
    void takeDamage(int damage);
    void updateTurn();
};
#endif