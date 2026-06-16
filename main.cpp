#include <iostream>
#include "BattleManager.h"

using namespace std;

int main() {

    Unit* playerHero = new Unit("Paladin Knight", 200, 60);
    playerHero->setShield(new Shield(50, 0));
    playerHero->setWeapon(new PhysicalWeapon("Heavy Broadsword", 30, 15, 0.15));
    Unit* enemyBot = new Unit("Scout Drone-X", 150, 100);
    enemyBot->setShield(new Shield(30, 4));
    enemyBot->setWeapon(new EnergyWeapon("Laser Discharger", 20, 20, 10));

    BattleManager game(playerHero, enemyBot);

    game.startBattle();

    return 0;
}