#ifndef SHIELD_H
#define SHIELD_H

using namespace std;

class Shield {
private:
    int capacity;
    int maxCapacity;
    int regenRate;

public:
    Shield(int maxCap, int regen);
    ~Shield();

    int getCapacity() const;
    void setCapacity(int value);
    void regenerate();
};

#endif