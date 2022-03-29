#include "Enemy.h"
Enemy::Enemy(){

    this->this_type = 3;

    this->enmap[0]="./images/car_1.png";
    this->enmap[1]="./images/car_2.png";
    this->enmap[2]="./images/car_3.png";
    this->enmap[3]="./images/police.png";

    this->pos[0]=(VAR::POS_1);
    this->pos[1]=(VAR::POS_2);
    this->pos[2]=(VAR::POS_3);
    this->pos[3]=(VAR::POS_4);
    
    this->initTexture();
    this->initSprite();
    this->speed = VAR::ENEMY_SPEED;
    
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

}

void Enemy::set_position(){
    this->sprite.setPosition(sf::Vector2f(this->pos[this->this_type],100));
}

sf::Sprite Enemy::get_cars_sprite(){
    return this->sprite;
}