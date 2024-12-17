#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include "player/player.h"
#include "item/item.h"
#include "enemy/enemy.h"


class Game {
private:
    Player* player;
    Item* apple;
    Enemy enemy;
    bool running;
public:
    Game(sf::RenderWindow& window);
    ~Game() {
        delete player;
        delete apple;
        player = nullptr;
        apple = nullptr;
    }
    bool isRunning() { return running; }
    void setRunning(bool running) { this->running = running; }
    void run(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window, sf::Event event);
};


#endif