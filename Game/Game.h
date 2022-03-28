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
        sf::RenderWindow* mywin;
        void initWindow();
};