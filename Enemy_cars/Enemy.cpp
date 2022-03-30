#include "Enemy.h"
#include <stdio.h>

Enemy::Enemy(){
    this->this_type = 0 + rand() % 4;
    this->speed=VAR::ENEMY_SPEED;
    this->enmap[0]="./images/car_1.png";
    this->enmap[1]="./images/car_2.png";
    this->enmap[2]="./images/car_3.png";
    this->enmap[3]="./images/police.png";
    
    this->initTexture();
    this->initSprite();
    
}

Enemy::~Enemy(){
}

void Enemy::initTexture(){
    this->texture.loadFromFile(this->enmap[this->this_type]);
}

void Enemy::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.15f,0.15f);
    this->set_position();
}

void Enemy::move(){
    this->sprite.setPosition(this->get_x(),this->get_y()+this->speed);
}

void Enemy::set_position(){
    this->this_type = 0 + rand() % 4;

    this->pos[0]=(VAR::POS_1);
    this->pos[1]=(VAR::POS_2);
    this->pos[2]=(VAR::POS_3);
    this->pos[3]=(VAR::POS_4);

    this->sprite.setPosition(sf::Vector2f(this->pos[this->this_type],(-100+rand() % 100)));
}

sf::Sprite Enemy::get_cars_sprite(){
    return this->sprite;
}