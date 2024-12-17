#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include "player/player.h"
#include <string>
using std::string;

class Item {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    string type;
    bool do_render = true;
public: 
    Item(string type, sf::RenderWindow& window);
    ~Item();
    string getType() { return type; }
    sf::Sprite getSprite() { return sprite; }
    bool getRenderState() { return do_render; }
    void handlePlayerCollect(Player player);
};


#endif