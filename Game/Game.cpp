#include "Game.h"

Game::Game(){

    this->initWindow();
}

Game::~Game(){

    delete this->mywin;
}

void Game::initTexture(){
    this->mywin_texture.loadFromFile("images/background.png");
    this->mywin_texture.setSmooth(true);
}

void Game::initSprite(){
    this->mywin_sprite.setTexture(this->mywin_texture);
    this->mywin_sprite.scale(0.9f,0.9f);
}

void Game::initWindow(){

    this->mywin = new sf::RenderWindow(sf::VideoMode(VAR::WIDTH, VAR::HEIGHT),"DODGE POLICE", sf::Style::Close | sf::Style::Titlebar);
    this->mywin->setFramerateLimit(VAR::FPS);
    this->initTexture();
    this->initSprite();
    this->mywin->setVerticalSyncEnabled(false);
}
void Game::update(){
    this->mywin->clear();
    this->mywin->draw(this->mywin_sprite);
    this->mywin->display();

}

void Game::render(){
    sf::Event e;
    while(this->mywin->pollEvent(e)){
        if(e.Event::type==sf::Event::Closed || (e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Escape)){
            this->mywin->close();
        }
    }
}

void Game::run(){
    while(this->mywin->isOpen()){
        this->render();
        this->update();
    }
}