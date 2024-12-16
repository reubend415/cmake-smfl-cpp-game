#include "player.h"


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

sf::CircleShape Player::getSprite() {
    return sprite;
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
    if ((w_pressed && s_pressed) || (a_pressed && d_pressed)) {
            sprite.setFillColor(DEFAULT_COLOR);
        } else if (w_pressed && d_pressed) {
            sprite.setFillColor(sf::Color::Yellow);
            sprite.move(PLAYER_SPEED, -PLAYER_SPEED);
        } else if (w_pressed && a_pressed) {
            sprite.setFillColor(sf::Color::Magenta);
            sprite.move(-PLAYER_SPEED, -PLAYER_SPEED);
        } else if (s_pressed && d_pressed) {
            sprite.setFillColor(sf::Color::Yellow);
            sprite.move(PLAYER_SPEED, PLAYER_SPEED);
        } else if (s_pressed && a_pressed) {
            sprite.setFillColor(sf::Color::Magenta);
            sprite.move(-PLAYER_SPEED, PLAYER_SPEED);
        } else if (w_pressed) {
            sprite.setFillColor(sf::Color::Blue);
            sprite.move(0, -PLAYER_SPEED);
        } else if (a_pressed) {
            sprite.setFillColor(sf::Color::Magenta);
            sprite.move(-PLAYER_SPEED, 0);
        } else if (s_pressed) {
            sprite.setFillColor(sf::Color::Green);
            sprite.move(0, PLAYER_SPEED);
        } else if (d_pressed) {
            sprite.setFillColor(sf::Color::Yellow);
            sprite.move(PLAYER_SPEED, 0);
        } else {
            sprite.setFillColor(DEFAULT_COLOR);
        }
}


void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::collectApple() {
    apples_held++;
    std::cout << "Apples Held: " << apples_held << std::endl;
}
