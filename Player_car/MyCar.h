#include "../Enemy_cars/Object.h"
#include <SFML/Graphics.hpp>
#include "../constants.h"
#include "CarInfo.h"

class MyCar: public MyObject, public CarInfo {
    public:
        MyCar();
        ~MyCar();
        void set_center();
        void initfont();
        void init_score();
        void init_level();
        void init_attemp();
        void initSprite() override;
        void initTexture() override;
        void move_dir(const float x, const float y);
        sf::Sprite get_player_sprite();
    private:
        int myscore, mylevel, myattemp;
        float speed;  
        sf::Font font; 
};