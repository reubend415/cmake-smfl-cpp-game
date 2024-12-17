#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "utils/gameobject.h"
#include <iostream>


class Player : public GameObject {
    const int PLAYER_SPEED = 3;
    const sf::Color DEFAULT_COLOR = sf::Color(80, 0, 0);
    int apples_held;

    bool w_pressed = false;
    bool a_pressed = false;
    bool s_pressed = false;
    bool d_pressed = false;

public:
    Player(sf::RenderWindow& window);
    void handleKeyPress(sf::Keyboard::Scancode scancode);
    void handleKeyRelease(sf::Keyboard::Scancode scancode);
    void handlePlayerMove();
    void collectApple();

};

#endif