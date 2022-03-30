#include <SFML/Graphics.hpp>
#include "../constants.h"

class PauseGame{
    public:
        PauseGame();
        ~PauseGame();
        void initSprite();
        void initTexture();
        bool check_input(sf::RenderWindow &para);
        void update();
        sf::Text get_text() {return this->text;}
        sf::Sprite get_sprite() {return this->sprite;}
    private:
        sf::Font font;
        sf::Text text;
        sf::Sprite sprite;
        sf::Texture texture;
};