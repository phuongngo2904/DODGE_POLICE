#include "../Enemy_cars/Object.h"
#include <SFML/Graphics.hpp>
#include "../constants.h"

class MyCar:public MyObject{
    public:
        MyCar();
        ~MyCar();
        void set_center();
        void initSprite();
        void initTexture();
        sf::Sprite get_player_sprite();
    private:
        sf::Sprite player_sprite;
        sf::Texture player_texture;   
};