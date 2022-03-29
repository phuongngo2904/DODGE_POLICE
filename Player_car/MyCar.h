#include "../Enemy_cars/Object.h"
#include <SFML/Graphics.hpp>
#include "../constants.h"

class MyCar: public MyObject{
    public:
        MyCar();
        ~MyCar();
        void set_center() ;
        void initSprite() override;
        void initTexture() override;
        void move_dir(const float x, const float y);
        sf::Sprite get_player_sprite();
    private:
        float speed;   
};