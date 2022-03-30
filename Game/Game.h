#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../constants.h"
#include "../Player_car/MyCar.h"
#include "../Enemy_cars/Object.h"
#include "../Enemy_cars/Enemy.h"
#include "../Game/PauseGame.h"
#include "../Game/GameOver.h"
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
        void reset_game();
        void pause_game();
        void car_crash();
        void game_over();
    private:
        bool PAUSE;
        bool LOST;
        bool GAME_OVER;
    	float Timer;
	    float TimerMax;
        sf::Sprite mywin_sprite;
        sf::Texture mywin_texture;
        sf::RenderWindow* mywin;
        GameOver* go;
        MyCar* player;
        PauseGame* pause;
        std::vector<Enemy*> enemy;
        

};