#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "utils/gameobject.h"
#include <iostream>


class Player : public GameObject {
    const int PLAYER_SPEED = 3;
    const sf::Color DEFAULT_COLOR = sf::Color(80, 0, 0);
    int apples_held;
    sf::CircleShape sprite;

    bool w_pressed = false;
    bool a_pressed = false;
    bool s_pressed = false;
    bool d_pressed = false;

public:
    Player(sf::RenderWindow& window) : sprite(sf::CircleShape(50)) {
        sprite.setPosition(((window.getSize().x / 2) - 50), ((window.getSize().y / 2) - 50));
        sprite.setFillColor(DEFAULT_COLOR);
        apples_held = 0;
    }

    sf::CircleShape getSprite();
    void handleKeyPress(sf::Keyboard::Scancode scancode);
    void handleKeyRelease(sf::Keyboard::Scancode scancode);
    void handlePlayerMove();
    void draw(sf::RenderWindow& window);
    void collectApple();

};

#endif