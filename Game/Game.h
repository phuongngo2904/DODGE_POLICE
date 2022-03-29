#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../constants.h"
#include "../Player_car/MyCar.h"
#include "../Enemy_cars/Object.h"
#include "../Enemy_cars/Enemy.h"

class Game{
    public:
        Game();
        ~Game();
        void run();
        void update();
        void events();
        void initWindow();
        void initPlayer();
        void initEnemy();
        void initSprite();
        void initTexture();
    private:
        sf::Sprite mywin_sprite;
        sf::Texture mywin_texture;
        sf::RenderWindow* mywin;
        MyCar* player;
        Enemy* enemy;
        

};