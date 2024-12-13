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

    bool w_pressed = false;
    bool a_pressed = false;
    bool s_pressed = false;
    bool d_pressed = false;
    bool nothing_pressed = true;

    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.scancode) {
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
                    case sf::Keyboard::Scan::Escape:
                        window.close();
                        break;
                    default:
                        break;
                }
            }

        }

        if (w_pressed && d_pressed) {
            circle.setFillColor(sf::Color::Yellow);
            circle.move(1, -1);
        } else if (w_pressed && a_pressed) {
            circle.setFillColor(sf::Color::Magenta);
            circle.move(-1, -1);
        } else if (s_pressed && d_pressed) {
            circle.setFillColor(sf::Color::Yellow);
            circle.move(1, 1);
        } else if (s_pressed && a_pressed) {
            circle.setFillColor(sf::Color::Magenta);
            circle.move(-1, 1);
        } else if (w_pressed) {
            circle.setFillColor(sf::Color::Blue);
            circle.move(0, -1);
        } else if (a_pressed) {
            circle.setFillColor(sf::Color::Magenta);
            circle.move(-1, 0);
        } else if (s_pressed) {
            circle.setFillColor(sf::Color::Green);
            circle.move(0, 1);
        } else if (d_pressed) {
            circle.setFillColor(sf::Color::Yellow);
            circle.move(1, 0);
        } else {
            circle.setFillColor(color);
        }
        
        // Clear, draw, display
        window.clear();

        window.draw(circle);

        window.display();
    }
}
