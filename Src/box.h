
#ifndef P5SFML_BOX_H
#define P5SFML_BOX_H
#include "manual.h"




class Box{
public:
    Box(sf::Vector2f position,int type);


private:
    int type;
    sf::Vector2f boxposition;
    sf::Sprite boxsprite;
    sf::Texture boxtextuture;

};








#endif //P5SFML_BOX_H
