#include "manual.h"
#include "box.h"


Box::Box(sf::Vector2f position,int boxtype,float tileSize)

{
    boxposition = position;
    if (boxtype == 1){
        boxtextuture.loadFromFile(BOXT1ADD);
    } else{
        boxtextuture.loadFromFile(BOXT2ADD);
    }
    boxsprite.setTexture(boxtextuture);
    boxsprite.setScale(static_cast<float>(tileSize) / boxtextuture.getSize().x,
                       static_cast<float>(tileSize) / boxtextuture.getSize().y);

    type = boxtype;
}


sf::Sprite Box::get_box_sprite() {return boxsprite;}
sf::Vector2f Box::get_box_position() {return boxposition;}
void Box::fixsprite() {
    boxsprite.setPosition(boxposition);
}
