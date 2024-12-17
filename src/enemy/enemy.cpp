#include "enemy.h"
#include <iostream>

Enemy::Enemy() {
    if (!texture.loadFromFile("assets/textures/Skull.png")) {
        std::cout << "Error loading enemy texture!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(350, 200);
    sprite.setScale(5, 5);
}

bool Enemy::handleAttackPlayer(Player player) {
    if (sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
        return true;
    }
    return false;
}

// Hello

