
#ifndef P5SFML_BOY_H
#define P5SFML_BOY_H
#include <SFML/Graphics.hpp>
#include "manual.h"
#include "bomb.h"
#include <vector>

class Boy
{
public:
    Boy(sf::RenderWindow* Window);


    sf::Sprite getboysprite();
    void handleMovement();
    void checkBounds();
    void update();
    std::vector<Bomb*> bombs;


private:
    sf::RenderWindow* mainWindow;
    const float boySpeed;
    sf::Vector2f boyVelocity;
    sf::Vector2f boyPosition;
    sf::Sprite boySprite;
    sf::Texture downTexture;
    sf::Texture upTexture;
    sf::Texture rightTexture;
    sf::Texture leftTexture;



};

#endif //P5SFML_BOY_H
