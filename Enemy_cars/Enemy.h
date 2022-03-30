#include "Object.h"
#include <SFML/Graphics.hpp>
#include "../constants.h"
#include <vector>
#include <iostream>
#define SIZE 4

class Enemy : public MyObject {
    public:
        Enemy();
        ~Enemy();
        void set_position();
        void move();
        void check_boundary();        
        void initSprite() override;
        void initTexture() override;
        sf::Sprite get_cars_sprite();
    private:
        float speed;
        int cool_down;
        int this_type;
        std::string enmap[SIZE];
        int pos[SIZE];
};  