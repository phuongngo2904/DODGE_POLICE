#include "../Enemy_cars/Object.h"
#include <SFML/Graphics.hpp>
#include "../constants.h"
#include "CarInfo.h"

class MyCar: public MyObject, public CarInfo {
    public:
        MyCar();
        ~MyCar();
        void set_score(int para) {this->myscore+=para;}
        void set_level(int para) {this->mylevel+=para;}
        void set_attemp(int para) {this->myattemp-=para;}
        void reset_attemp(int para) {this->myattemp=para;}
        void reset_score(int para) {this->myscore=para;}
        void reset_level(int para) {this->mylevel=para;}
        int  get_current_attemp() {return this->myattemp;}
        int  get_current_score() {return this->myscore;}
        int  get_current_level() {return this->mylevel;}
        void set_center();
        void initfont();
        void init_score();
        void init_level();
        void init_attemp();
        void update_score_level_attemp();
        void initSprite() override;
        void initTexture() override;
        bool collide(sf::Sprite enemy);
        void move_dir(const float x, const float y);
        sf::Sprite get_player_sprite();
    private:
        int myscore, mylevel, myattemp;
        float speed;  
        sf::Font font; 
};