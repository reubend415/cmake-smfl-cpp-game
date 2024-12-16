#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include "player/player.h"
#include "item/item.h"


class Game {
private:
    Player* player;
    Item* apple;
public:
    Game(sf::RenderWindow& window);
    ~Game() {
        delete player;
    }
    void run(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window, sf::Event event);
};


#endif