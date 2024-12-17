#include "player.h"
#include <iostream>

Player::Player(sf::RenderWindow& window) {
    type = "player";
    do_render = true;
    if (!texture.loadFromFile("assets/textures/Wizard.png")) {
        std::cout << "Error loading player texture!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    sprite.setScale(5, 5);
    sprite.setPosition((window.getSize().x / 2), (window.getSize().y / 2));
}

void Player::handleKeyPress(sf::Keyboard::Scancode scancode) {
    switch (scancode) {
        case sf::Keyboard::Scan::W:
            w_pressed = true;
            break;
        case sf::Keyboard::Scan::A:
            a_pressed = true;
            break;
        case sf::Keyboard::Scan::S:
            s_pressed = true;
            break;
        case sf::Keyboard::Scan::D:
            d_pressed = true;
            break;
        default:
            break;
    }
}



void Player::handleKeyRelease(sf::Keyboard::Scancode scancode) {
    switch (scancode) {
        case sf::Keyboard::Scan::W:
            w_pressed = false;
            break;
        case sf::Keyboard::Scan::A:
            a_pressed = false;
            break;
        case sf::Keyboard::Scan::S:
            s_pressed = false;
            break;
        case sf::Keyboard::Scan::D:
            d_pressed = false;
            break;
        default:
            break;
    }
}

void Player::handlePlayerMove() {
    bool do_nothing = false;
    if ((w_pressed && s_pressed) || (a_pressed && d_pressed)) {
        do_nothing = !do_nothing;
    } else if (w_pressed && d_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 32, 16, 16));
        sprite.move(PLAYER_SPEED, -PLAYER_SPEED);
    } else if (w_pressed && a_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        sprite.move(-PLAYER_SPEED, -PLAYER_SPEED);
    } else if (s_pressed && d_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 32, 16, 16));
        sprite.move(PLAYER_SPEED, PLAYER_SPEED);
    } else if (s_pressed && a_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        sprite.move(-PLAYER_SPEED, PLAYER_SPEED);
    } else if (w_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 48, 16, 16));
        sprite.move(0, -PLAYER_SPEED);
    } else if (a_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        sprite.move(-PLAYER_SPEED, 0);
    } else if (s_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
        sprite.move(0, PLAYER_SPEED);
    } else if (d_pressed) {
        sprite.setTextureRect(sf::IntRect(0, 32, 16, 16));
        sprite.move(PLAYER_SPEED, 0);
    }
}




void Player::collectApple() {
    apples_held++;
    std::cout << "Apples Held: " << apples_held << std::endl;
}
