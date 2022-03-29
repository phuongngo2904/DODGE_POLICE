#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../constants.h"
#include "../Player_car/MyCar.h"
#include "../Enemy_cars/Object.h"

class Game{
    public:
        Game();
        virtual ~Game();
        void run();
        void update();
        void render();
        void initWindow();
        void initPlayer();
        void initSprite();
        void initTexture();
    private:
        sf::Sprite mywin_sprite;
        sf::Texture mywin_texture;
        sf::RenderWindow* mywin;
        MyCar* player;
        

};