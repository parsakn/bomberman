#ifndef P5SFML_BOMB_H
#define P5SFML_BOMB_H

#include "manual.h"




class Bomb{
public:
    Bomb(sf::RenderWindow* Windows,sf::Vector2f bombposition);

    void update();
    sf::Sprite getbombsprite(){
        return bombsprite;
    }

private:
    sf::RenderWindow* mainWindow;
    sf::Vector2f bombposition;
    sf::Sprite bombsprite;
    sf::Texture bombtexture;

};



#endif //P5SFML_BOMB_H
