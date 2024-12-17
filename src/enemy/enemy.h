#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "player/player.h"

using std::string;

class Enemy {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    string type = "enemy";
    bool do_render = true;
public:
    Enemy();
    // ~Enemy();
    bool getRenderState() { return do_render; }
    sf::Sprite getSprite() { return sprite; }
    string getType() { return type; }
    bool handleAttackPlayer(Player player);
    // void handlePlayerAttack(Player player);
};

#endif