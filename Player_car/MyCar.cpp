#include "MyCar.h"
#include <filesystem>
#include <iostream>

MyCar::MyCar(){
    this->initTexture();
    this->initSprite();
    this->speed = VAR::PLAYER_SPEED;
}
MyCar::~MyCar(){
}
void MyCar::set_center(){
    this->sprite.setPosition(sf::Vector2f(VAR::POS_X_CENTER,VAR::POS_Y_CENTER));
}

void MyCar::initTexture(){
    this->texture.loadFromFile("./images/user_car.png");
}

void MyCar::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.15f,0.15f);
    this->set_center();
    
}
void MyCar::move_dir(const float x, const float y){
    this->sprite.move(x*this->speed,this->speed*y);
}

sf::Sprite MyCar::get_player_sprite(){
    return this->sprite;
}