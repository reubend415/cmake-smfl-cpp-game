#include "item.h"
#include <iostream>

Item::Item(string type, sf::RenderWindow& window): type(type){
    if (type == "apple") {
        if(!texture.loadFromFile("assets/textures/Apple.png")) {
            std::cout << "Error loading item texture!" << std::endl;
        }
        sprite.setTexture(texture);
        sprite.setPosition(1250, (window.getSize().y / 2));
        sprite.setScale(2.5, 2.5);
    }
}

Item::~Item() {
}

void Item::handlePlayerCollect(Player player) {
    if (sprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
        do_render = false;
        player.collectApple();
    }
}


