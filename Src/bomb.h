#ifndef P5SFML_BOMB_H
#define P5SFML_BOMB_H

#include "manual.h"




class Bomb{
public:
    Bomb(sf::Vector2f bombposition,float tileSize);

    void update();
    sf::Sprite getbombsprite(){
        return bombsprite;
    }
    sf::Clock timer;
    float elapsedSeconds;


private:

    sf::Vector2f bombposition;
    sf::Sprite bombsprite;
    sf::Texture bombtexture;
    float tileSize;

};



#endif //P5SFML_BOMB_H
