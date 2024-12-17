#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "player/player.h"
#include "utils/gameobject.h"

using std::string;

class Enemy : public GameObject {
private:
public:
    Enemy();
    bool handleAttackPlayer(Player player);
    // void handlePlayerAttack(Player player);
};

#endif