#include "game.h"
#include <iostream>
#include "player/player.h"


Game::Game(sf::RenderWindow& window) {
    player = new Player(window);
    if (!itemTexture.loadFromFile("assets/textures/Apple.png")) {
        std::cout << "Error loading texture!" << std::endl;
    }

    itemSprite.setTexture(itemTexture);
    itemSprite.setPosition(1250, (window.getSize().y / 2));
    itemSprite.setScale(2.5, 2.5);
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

    
    player->draw(window);
    window.draw(itemSprite);

    window.display();
}

