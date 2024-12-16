#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "player/player.h"


class Game {
private:
    Player* player;
public:
    Game(sf::RenderWindow& window) {
        player = new Player(window);
    };
    ~Game() {
        delete player;
    }
    void run(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window, sf::Event event);
};


#endif