#pragma once
#include <SFML/Graphics.hpp>

class MyObject{
    public:
        virtual void initSprite() = 0;
        virtual void initTexture() = 0;
        int get_x() {return this->sprite.getPosition().x;}
        int get_y() {return this->sprite.getPosition().y;}
    protected:
        sf::Sprite sprite;
        sf::Texture texture;
        
};