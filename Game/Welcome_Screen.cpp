#include "Welcome_Screen.h"

WelcomeWindow::WelcomeWindow(){
    this->initTexture();
    this->initSprite();
    this->initfont();
    this->inittext();
}

WelcomeWindow::~WelcomeWindow(){
    delete this;
}

void WelcomeWindow::initTexture(){
    this->cursor.loadFromFile("images/cur.png");
    this->texture.loadFromFile("images/background.png");
}

void WelcomeWindow::initSprite(){
    this->cursor_sprite.setTexture(this->cursor);
    this->cursor_sprite.scale(0.1f,0.1f);
    this->cursor_sprite.setPosition(sf::Vector2f(280,300));

    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.9f,0.9f);
}

void WelcomeWindow::initfont(){
    this->font.loadFromFile("./font/Rainshow.otf");
}

void WelcomeWindow::inittext(){
    this->text.setFont(this->font);
    this->text.setString("DODGE POLICE");
    this->text.setCharacterSize(50);
    this->text.setFillColor(sf::Color::Cyan);
    this->text.setPosition(200, 100);

    this->play.setFont(this->font);
    this->play.setString("PLAY");
    this->play.setCharacterSize(50);
    this->play.setFillColor(sf::Color::Cyan);
    this->play.setPosition(320, 280);

    this->exit.setFont(this->font);
    this->exit.setString("EXIT");
    this->exit.setCharacterSize(50);
    this->exit.setFillColor(sf::Color::Cyan);
    this->exit.setPosition(320, 360);

}

void WelcomeWindow::move_up(){
    this->cursor_sprite.setPosition(sf::Vector2f(280,300));
}

void WelcomeWindow::move_down(){
    this->cursor_sprite.setPosition(sf::Vector2f(280,380));
}

sf::Sprite WelcomeWindow::get_sprite() {return this->sprite;}

sf::Sprite WelcomeWindow::get_cursor_sprite() {return this->cursor_sprite;}

sf::Text WelcomeWindow::get_text() {return this->text;}

sf::Text WelcomeWindow::get_play_text() {return this->play;}

sf::Text WelcomeWindow::get_exit_text() {return this->exit;}