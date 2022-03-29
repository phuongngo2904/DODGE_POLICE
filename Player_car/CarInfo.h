#include <SFML/Graphics.hpp>
class CarInfo{
    public:
        sf::Text get_score() {return this->score;}
        sf::Text get_level() {return this->level;}
        sf::Text get_attemp() {return this->attemp;}
    protected:
        sf::Text score;
        sf::Text level;
        sf::Text attemp;

};