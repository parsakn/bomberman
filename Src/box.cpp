#include "manual.h"
#include "box.h"


Box::Box(sf::Vector2f position,int boxtype)

{
    boxposition = position;
    if (boxtype == 1){
        boxtextuture.loadFromFile(BOXT1ADD);
    } else{
        boxtextuture.loadFromFile(BOXT2ADD);
    }
    boxsprite.setTexture(boxtextuture);
    type = boxtype;
}
