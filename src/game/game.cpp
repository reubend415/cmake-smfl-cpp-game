#include "game.h"
#include <iostream>



Game::Game(sf::RenderWindow& window) {
    player = new Player(window);
    apple = new Item("apple", window);
    running = true;
}

void Game::run(sf::RenderWindow& window) {
    for (auto event = sf::Event(); window.pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        handleInput(window, event);
    }

    player->handlePlayerMove();
    


    // Clear, draw, display
    window.clear();

    
    if (player->getRenderState()) {
        window.draw(player->getSprite());
    }
    if (apple->getRenderState()) {
        apple->handlePlayerCollect(*player);
        window.draw(apple->getSprite());
    }

    if (enemy.getRenderState()) {
        if (enemy.handleAttackPlayer(*player)) {
            setRunning(false);
        }
        window.draw(enemy.getSprite());
    }

    window.display();
}



void Game::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.scancode) {
            case sf::Keyboard::Scan::W:
            case sf::Keyboard::Scan::A:
            case sf::Keyboard::Scan::S:
            case sf::Keyboard::Scan::D:
                player->handleKeyPress(event.key.scancode);
                break;
            case sf::Keyboard::Scan::Escape:
                window.close();
                break;
            default:
                break;
        }
    }

    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.scancode) {
            case sf::Keyboard::Scan::W:
            case sf::Keyboard::Scan::A:
            case sf::Keyboard::Scan::S:
            case sf::Keyboard::Scan::D:
                player->handleKeyRelease(event.key.scancode);
                break;
            default:
                break;
        }
    }
}

