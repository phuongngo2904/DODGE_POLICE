#include "MyCar.h"
#include <filesystem>
#include <iostream>

MyCar::MyCar(){
    this->set_x(VAR::POS_X_CENTER);
    this->set_y(VAR::POS_Y_CENTER);
    this->initTexture();
    this->initSprite();
    this->speed = VAR::PLAYER_SPEED;
}
MyCar::~MyCar(){
}
void MyCar::set_center(){
    this->player_sprite.setPosition(sf::Vector2f(VAR::POS_X_CENTER,VAR::POS_Y_CENTER));
}

void MyCar::initTexture(){
    this->player_texture.loadFromFile("./images/user_car.png");
}

void MyCar::initSprite(){


    this->player_sprite.setTexture(this->player_texture);
    this->player_sprite.scale(0.15f,0.15f);
    this->set_center();
}
void MyCar::move_dir(const float x, const float y){
    this->player_sprite.move(x*this->speed,this->speed*y);
}

sf::Sprite MyCar::get_player_sprite(){
    return this->player_sprite;
}