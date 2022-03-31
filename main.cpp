#include "Game/Game.h"
#include "Game/Welcome_Screen.h"
#include <SFML/Graphics.hpp>
#include "constants.h"

int main(){
    bool start_game=false;
    sf::RenderWindow* main_win = new sf::RenderWindow(sf::VideoMode(VAR::WIDTH, VAR::HEIGHT),"DODGE POLICE",sf::Style::Close|sf::Style::Default);
    main_win->setFramerateLimit(VAR::FPS);
    main_win->setVerticalSyncEnabled(false);
    WelcomeWindow* wc= new WelcomeWindow();
    sf::Event e;
    while(main_win->isOpen()){
        main_win->draw(wc->get_sprite());
        main_win->draw(wc->get_text());
        main_win->draw(wc->get_play_text());
        main_win->draw(wc->get_exit_text());
        main_win->draw(wc->get_cursor_sprite());
        while(main_win->pollEvent(e)){
            if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Enter) && wc->get_cursor_sprite().getPosition().y == 380){
                main_win->close();
            }
            if((e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Enter) && wc->get_cursor_sprite().getPosition().y == 300){
                start_game=true;
                main_win->close();
            }
            if(e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Down){
                wc->move_down();
            }
            if(e.Event::KeyPressed && e.Event::key.code==sf::Keyboard::Up){
                wc->move_up();
            }
        }
        main_win->display();
    }
    delete main_win;
    delete wc;
    if(start_game){
        Game game;
        game.run();
    }
    
}