#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    sf::Color color(80, 0, 0);
    window.setFramerateLimit(144);

    std::cout << "Hello world!!" << std::endl;

    

    sf::CircleShape circle(100);
    circle.setPosition(((window.getSize().x / 2) - 100), ((window.getSize().y / 2) - 100));
    circle.setFillColor(color);

    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Clear, draw, display
        window.clear();

        window.draw(circle);

        window.display();
    }
}
