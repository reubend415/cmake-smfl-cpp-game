#include <SFML/Graphics.hpp>
#include <iostream>
#include "game/game.h"


int main() {
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project", sf::Style::Fullscreen);
    window.setFramerateLimit(144);

    std::cout << "Hello world!!" << std::endl;

    Game game(window);

    while (window.isOpen()) {
        game.run(window);
    }
}
