#include "manual.h"
#include "bomb.h"


Bomb::Bomb(sf::Vector2f bombpos,float tilesSize)

{
    tileSize = tilesSize;
    elapsedSeconds = 0;
    bombposition = bombpos;
    bombtexture.loadFromFile(BOMBADD);
    bombsprite.setTexture(bombtexture);
}

void Bomb::update() {
    elapsedSeconds = timer.getElapsedTime().asSeconds();
    bombsprite.setScale((tileSize) / this->bombtexture.getSize().x,
                        (tileSize) / this->bombtexture.getSize().y);
    bombsprite.setPosition(bombposition);

}

