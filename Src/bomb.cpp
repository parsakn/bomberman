#include "manual.h"
#include "bomb.h"


Bomb::Bomb(sf::RenderWindow* window,sf::Vector2f bombpos) :
mainWindow(window)
{
    bombposition = bombpos;
    bombtexture.loadFromFile(BOMBADD);
    bombsprite.setTexture(bombtexture);
}

void Bomb::update() {
    bombsprite.setScale(static_cast<float>(gridSize) / this->bombtexture.getSize().x,
                        static_cast<float>(gridSize) / this->bombtexture.getSize().y);
    bombsprite.setPosition(bombposition);
}

