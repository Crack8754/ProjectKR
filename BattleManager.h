#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include "Unit.h"

using namespace std;

class BattleManager {
private:
    Unit* player;
    Unit* enemy;
    int round;

public:
    BattleManager(Unit* p, Unit* e);
    ~BattleManager();

    void startBattle();
};

#endif