#include <SFML/Graphics.hpp>
#include "../constants.h"
class WelcomeWindow {
    public:
        WelcomeWindow();
        ~WelcomeWindow();
        void initTexture();
        void initSprite();
        void initfont();
        void inittext();
        void move_down();
        void move_up();
        sf::Sprite get_sprite();
        sf::Sprite get_cursor_sprite();
        sf::Text get_text();
        sf::Text get_play_text();
        sf::Text get_exit_text();
    private:
        sf::Texture cursor;
        sf::Sprite cursor_sprite;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Font font;
        sf::Text text;
        sf::Text play;
        sf::Text exit;
};