#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
using std::string;

class GameObject {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    string type;
    bool do_render;
public:
    GameObject(): type("entity") {}
    sf::Sprite getSprite() { return sprite; }
    string getType() { return type; }
    bool getRenderState() { return do_render; }
    void setRenderState(bool do_render) { this->do_render = do_render; }
};


#endif