#include "BattleManager.h"
#include <iostream>

using namespace std;

BattleManager::BattleManager(Unit* p, Unit* e) {
    player = p;
    enemy = e;
    round = 1;
}

BattleManager::~BattleManager() {
    delete player;
    delete enemy;
}

void BattleManager::startBattle() {
    cout << "--- START OF BATTLE ---\n";

    while (player->getHealth() > 0 && enemy->getHealth() > 0) {
        cout << "Round " << round << "\n";
        cout << "  " << player->getName() << ": HP=" << player->getHealth() << ", Energy=" << player->getEnergy() << "\n";
        cout << "  " << enemy->getName() << ": HP=" << enemy->getHealth() << ", Energy=" << enemy->getEnergy() << "\n";

        cout << "Press [Enter] for attack...";
        cin.get(); 

        cout << "Player's turn:\n";
       Weapon* pWeapon = player->getWeapon(); 
        
        if (player->getEnergy() >= pWeapon->getEnergyCost()) {
            player->useEnergy(pWeapon->getEnergyCost());
            int damageDealt = pWeapon->calculateDamage();
            enemy->takeDamage(damageDealt);
        } else {
            cout << "  Skipping turn (not enough energy).\n";
        }

        if (enemy->getHealth() <= 0) {
            break; 
        }

        cout << "Enemy's turn:\n";
        Weapon* eWeapon = enemy->getWeapon();
        
        if (enemy->getEnergy() >= eWeapon->getEnergyCost()) {
            enemy->useEnergy(eWeapon->getEnergyCost());
            int damageReceived = eWeapon->calculateDamage();
            player->takeDamage(damageReceived);
        } else {
            cout << "  Skipping turn (not enough energy).\n";
        }

        player->updateTurn();
        enemy->updateTurn();
        round++;
        cout << "\n";
    }

    cout << "--- BATTLE ENDED ---\n";
    if (player->getHealth() <= 0) {
        cout << "Winner: " << enemy->getName() << "\n";
    } else {
        cout << "Winner: " << player->getName() << "\n";
    }
}