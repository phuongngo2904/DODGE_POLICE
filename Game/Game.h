#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../constants.h"
class Game{
    public:
        Game();
        virtual ~Game();
        void run();
        void update();
        void render();
    private:
        sf::Sprite mywin_sprite;
        sf::Texture mywin_texture;
        sf::RenderWindow* mywin;
        void initWindow();
        void initSprite();
        void initTexture();
        
};