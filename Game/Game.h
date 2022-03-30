#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../constants.h"
#include "../Player_car/MyCar.h"
#include "../Enemy_cars/Object.h"
#include "../Enemy_cars/Enemy.h"
#include <vector>

class Game{
    public:
        Game();
        ~Game();
        void run();
        void update();
        void update_player();
        void update_enemy();
        void events();
        void initWindow();
        void initPlayer();
        void initEnemy();
        void initSprite();
        void initTexture();
        void pause_game();
    private:
        bool PAUSE;
    	float Timer;
	    float TimerMax;
        sf::Sprite mywin_sprite;
        sf::Texture mywin_texture;
        sf::RenderWindow* mywin;
        MyCar* player;
        std::vector<Enemy*> enemy;
        

};