#include "Game.h"
#include <iostream>

Game::Game(){
    this->PAUSE=false;
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
    this->initEnemy();
    this->mywin->setVerticalSyncEnabled(false);
}

void Game::initPlayer(){
    this->player = new MyCar();
}

void Game::initEnemy(){
    	this->TimerMax = 80.f;
	    this->Timer = this->TimerMax;
}

void Game::update_player(){
    this->player->update_score_level_attemp();
    this->mywin->draw(this->player->get_player_sprite());
    this->mywin->draw(this->player->get_score());
    this->mywin->draw(this->player->get_level());
    this->mywin->draw(this->player->get_attemp());
}

void Game::update_enemy(){

    this->Timer += 0.5f;
    if(this->Timer >= this->TimerMax){
        this->enemy.push_back(new Enemy());
        this->Timer = 0.f;
    }
    int counter=0;
    for(auto *e: this->enemy){
        e->move();
        this->mywin->draw(e->get_cars_sprite());
        if(e->get_y()>VAR::HEIGHT){
            delete this->enemy.at(counter);
			this->enemy.erase(this->enemy.begin() + counter);
            this->player->set_score(1);
        }
		else if (e->get_cars_sprite().getGlobalBounds().intersects(this->player->get_player_sprite().getGlobalBounds())){
			this->player->set_attemp(1);
            //std::cout<<"CRASH"<<std::endl;
		}
        counter++;
    }
}

void Game::update(){
    this->mywin->clear();
    this->events();
    this->mywin->draw(this->mywin_sprite);
    this->update_player();
    this->update_enemy();
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
        if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Down) && this->player->get_y()<=510){
            this->player->move_dir(0.f,1.f);
        }
        if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Left)&& this->player->get_x()>=130){
            
            this->player->move_dir(-1.f,0.f);
        }
        if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Right)&& this->player->get_x()<=570){
            this->player->move_dir(1.f,0.f);
        }
        if(e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::P){
            this->PAUSE=true;
            this->pause = new PauseGame();
        }
    }
}

void Game::pause_game(){
    sf::Event e;
    while(this->mywin->pollEvent(e)){
        if(e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::S){
            this->PAUSE=false;
        }

    }
    this->mywin->draw(this->pause->get_sprite());
    this->mywin->draw(this->pause->get_text());
    this->mywin->display();
}
void Game::run(){

    while(this->mywin->isOpen()){
        if(this->PAUSE){
            this->pause_game();
            continue;
        }
        else this->update();
    }
}
