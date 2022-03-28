#include "Game.h"


Game::Game(){

    this->initWindow();
}

Game::~Game(){

    delete this->mywin;
}

void Game::initWindow(){

    this->mywin = new sf::RenderWindow(sf::VideoMode(VAR::WIDTH, VAR::HEIGHT),"DODGE POLICE", sf::Style::Close | sf::Style::Titlebar);
}
void Game::update(){


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