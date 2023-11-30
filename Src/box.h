
#ifndef P5SFML_BOX_H
#define P5SFML_BOX_H
#include "manual.h"




class Box{
public:
    Box(sf::Vector2f position,int type,float tilesize);
    sf::Sprite get_box_sprite();
    sf::Vector2f get_box_position();
    void fixsprite();


private:
    int type;
    sf::Vector2f boxposition;
    sf::Sprite boxsprite;
    sf::Texture boxtextuture;

};








#endif //P5SFML_BOX_H
