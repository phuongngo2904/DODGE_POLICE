#include "Game.h"
#include <iostream>
Game::Game(){

    this->initWindow();
}

Game::~Game(){

    delete this->mywin;
    delete this->player;
}

void Game::initTexture(){
    this->mywin_texture.loadFromFile("images/background.png");
}

void Game::initSprite(){
    this->mywin_sprite.setTexture(this->mywin_texture);
    this->mywin_sprite.scale(0.9f,0.9f);
}

void Game::initWindow(){
    this->mywin = new sf::RenderWindow(sf::VideoMode(VAR::WIDTH, VAR::HEIGHT),"DODGE POLICE",sf::Style::Close|sf::Style::Default);
    this->mywin->setFramerateLimit(VAR::FPS);
    this->initTexture();
    this->initSprite();
    this->initPlayer();
    this->mywin->setVerticalSyncEnabled(false);
}

void Game::initPlayer(){
    this->player = new MyCar();
}
void Game::update(){
    this->mywin->clear();
    this->events();
    this->mywin->draw(this->mywin_sprite);
    this->mywin->draw(this->player->get_player_sprite());
    this->mywin->display();
}

void Game::events(){
    sf::Event e;
    while(this->mywin->pollEvent(e)){
        if(e.Event::type==sf::Event::Closed || (e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Escape)){
            this->mywin->close();
        }
        if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Up) && this->player->get_y() >0){
            this->player->move_dir(0.f,-1.f);
        }
        if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Down) && this->player->get_y()<500){
            this->player->move_dir(0.f,1.f);
        }
        if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Left)&& this->player->get_x()>=150){
            
            this->player->move_dir(-1.f,0.f);
        }
        if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Right)&& this->player->get_x()<=550){
            this->player->move_dir(1.f,0.f);
        }
    }

}

void Game::run(){
    
    while(this->mywin->isOpen()){
        this->update();
    }
}
