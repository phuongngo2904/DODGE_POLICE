#include "PauseGame.h"

PauseGame::PauseGame(){
    this->font.loadFromFile("./font/Rainshow.otf");
    this->text.setFont(this->font);
    this->text.setString("Press P to continue...");
    this->text.setCharacterSize(35);
    this->text.setFillColor(sf::Color::Black);
    this->text.setPosition(200, VAR::HEIGHT/2);
    this->initTexture();
    this->initSprite();
}
PauseGame::~PauseGame(){}

void PauseGame::initTexture(){
    this->texture.loadFromFile("./images/background.png");
}

void PauseGame::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.9f,0.9f);
}

bool PauseGame::check_input(sf::RenderWindow &para){
    sf::Event e;
    while(para.pollEvent(e)){
        if(e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::P){
            return true;
        }
    }
    return false;
}