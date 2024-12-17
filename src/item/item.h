#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include "utils/gameobject.h"
#include "player/player.h"
#include <string>
using std::string;

class Item : public GameObject {
private:
public: 
    Item(string type, sf::RenderWindow& window);
    ~Item();
    void handlePlayerCollect(Player player);
};


#endif