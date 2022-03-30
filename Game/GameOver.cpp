#include "GameOver.h"

GameOver::GameOver(){
    this->font.loadFromFile("./font/Rainshow.otf");
    this->retry.setFont(this->font);
    this->retry.setString("Yes(y)/No(n)");
    this->retry.setCharacterSize(35);
    this->retry.setFillColor(sf::Color::Black);
    this->retry.setPosition(300, 250);

    this->text.setFont(this->font);
    this->text.setString("Game Over. Retry ?");
    this->text.setCharacterSize(35);
    this->text.setFillColor(sf::Color::Black);
    this->text.setPosition(250, 200);
    this->initTexture();
    this->initSprite();
}
GameOver::~GameOver(){
    delete this;
}

void GameOver::initTexture(){
    this->texture.loadFromFile("./images/background.png");
}

void GameOver::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.9f,0.9f);
}
