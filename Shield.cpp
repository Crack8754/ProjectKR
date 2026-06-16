#include "Shield.h"

using namespace std;

Shield::Shield(int maxCap, int regen) {
    maxCapacity = maxCap;
    capacity = maxCap;
    regenRate = regen;
}

Shield::~Shield() {}

int Shield::getCapacity() const { 
    return capacity; 
}

void Shield::setCapacity(int value) { 
    capacity = value; 
    if (capacity < 0) capacity = 0;
    if (capacity > maxCapacity) capacity = maxCapacity;
}

void Shield::regenerate() { 
    setCapacity(capacity + regenRate); 
}