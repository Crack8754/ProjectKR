#ifndef WEAPON_H
#define WEAPON_H

#include <string>

using namespace std;

class Weapon {
protected:
    string name;
    int baseDamage;
    int energyCost;

public:
    Weapon(string wName, int dmg, int cost);
    virtual ~Weapon();

    string getName() const;
    int getBaseDamage() const;
    int getEnergyCost() const;

    virtual int calculateDamage();
};

class PhysicalWeapon : public Weapon {
private:
    double critChance;

public:
    PhysicalWeapon(string wName, int dmg, int cost, double chance);
    ~PhysicalWeapon();

    virtual int calculateDamage();
};

class EnergyWeapon : public Weapon {
private:
    int armorPiercing;

public:
    EnergyWeapon(string wName, int dmg, int cost, int pierce);
    ~EnergyWeapon();

    virtual int calculateDamage();
};

#endif