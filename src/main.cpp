#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"


int main() {
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    sf::Color color(80, 0, 0);
    window.setFramerateLimit(144);

    std::cout << "Hello world!!" << std::endl;

    Player player(window);

    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.scancode) {
                    case sf::Keyboard::Scan::W:
                    case sf::Keyboard::Scan::A:
                    case sf::Keyboard::Scan::S:
                    case sf::Keyboard::Scan::D:
                        player.handleKeyPress(event.key.scancode);
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
                        player.handleKeyRelease(event.key.scancode);
                        break;
                    default:
                        break;
                }
            }

        }

        player.handlePlayerMove();
        
        // Clear, draw, display
        window.clear();

        player.draw(window);

        window.display();
    }
}
