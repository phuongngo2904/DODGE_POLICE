#include <SFML/Graphics.hpp>
#include "../constants.h"

class GameOver{
    public:
        GameOver();
        ~GameOver();
        void initSprite();
        void initTexture();
        sf::Text get_text() {return this->text;}
        sf::Text get_retry_text() {return this->retry;}
        sf::Sprite get_sprite() {return this->sprite;}
    private:
        sf::Text retry;
        sf::Font font;
        sf::Text text;
        sf::Sprite sprite;
        sf::Texture texture;
};