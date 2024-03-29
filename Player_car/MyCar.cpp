#include "MyCar.h" 
#include <iostream>

MyCar::MyCar(){
    this->myscore=VAR::SCORE;
    this->mylevel=VAR::LEVEL;
    this->myattemp=VAR::PLAYER_LIFE;
    this->initfont();
    this->init_score();
    this->init_level();
    this->init_attemp();
    this->initTexture();
    this->initSprite();
    this->speed = VAR::PLAYER_SPEED;
}

MyCar::~MyCar(){
    delete this;
}

void MyCar::set_center(){
    this->sprite.setPosition(sf::Vector2f(VAR::POS_X_CENTER,VAR::POS_Y_CENTER));
}

void MyCar::initfont(){
    this->font.loadFromFile("./font/Rainshow.otf");
}

void MyCar::init_score(){
    this->score.setFont(font);
    this->score.setString("Score: " + std::to_string(this->myscore));
    this->score.setCharacterSize(25);
    this->score.setFillColor(sf::Color::Yellow);
    this->score.setPosition(0, 55);
}

void MyCar::init_level(){
    this->level.setFont(font);
    this->level.setString("Level: " + std::to_string(this->mylevel));
    this->level.setCharacterSize(25);
    this->level.setFillColor(sf::Color::Yellow);
    this->level.setPosition(0, 95);
}

void MyCar::init_attemp(){
    this->attemp.setFont(font);
    this->attemp.setString("Life: " + std::to_string(this->myattemp));
    this->attemp.setCharacterSize(25);
    this->attemp.setFillColor(sf::Color::Yellow);
    this->attemp.setPosition(0, 135);
}

void MyCar::initTexture(){
    this->texture.loadFromFile("./images/user_car.png");
}

void MyCar::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.12f,0.12f);
    this->set_center();
    
}

void MyCar::update_score_level_attemp(){
    this->score.setString("Score: " + std::to_string(this->myscore));
    this->level.setString("Level: " + std::to_string(this->mylevel));
    this->attemp.setString("Life: " + std::to_string(this->myattemp));
}

void MyCar::move_dir(const float x, const float y){
    this->sprite.move(x*this->speed,this->speed*y);
}

sf::Sprite MyCar::get_player_sprite(){
    return this->sprite;
}

bool MyCar::collide(sf::Sprite enemy){
    //std::cout<<enemy.getPosition().x <<"--"<<this->sprite.getPosition().x <<std::endl; // DEBUG
    if( (enemy.getPosition().y + 70 >= this->sprite.getPosition().y) && 
        (enemy.getPosition().x+40 >= this->sprite.getPosition().x) &&
        (enemy.getPosition().x-30 <= this->sprite.getPosition().x) &&
        (enemy.getPosition().y -50 <= this->sprite.getPosition().y)
        )
    {
        return true;
    }
    return false;

}