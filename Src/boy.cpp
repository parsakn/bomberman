#include "boy.h"
#include "manual.h"


Boy::Boy(sf::RenderWindow* window) :
        mainWindow(window),
        boySpeed(2.0f),
        boyVelocity(0, 0),
        boyPosition(0, 0)


{
    downTexture.loadFromFile(BOYDOWNMOVEADD);
    upTexture.loadFromFile(BOYUPMOVEADD);
    rightTexture.loadFromFile(BOYRIGHTMOVEADD);
    leftTexture.loadFromFile(BOYLEFTMOVEADD);
    boySprite.setTexture(downTexture);
}


sf::Vector2f bombposfixer(sf::Vector2f boyposition){
    boyposition.x = boyposition.x + (gridSize/2);
    boyposition.y = boyposition.y + (gridSize/2);
    float bombpositionx = boyposition.x - ( static_cast<int>(boyposition.x) % gridSize );
    float bombpositiony = boyposition.y - ( static_cast<int>(boyposition.y) % gridSize );

    return sf::Vector2f(bombpositionx,bombpositiony);


}

sf::Sprite Boy::getboysprite(){
    return boySprite;
}

void Boy::handleMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        bombs.push_back(new Bomb(mainWindow,bombposfixer(boyPosition)));
        boyVelocity.x = 0;
        boyVelocity.y = 0;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        boyVelocity.y = -boySpeed;
        this->boySprite.setTexture(upTexture);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        boyVelocity.y = boySpeed;
        this->boySprite.setTexture(downTexture);
    }
    else
    {
        boyVelocity.y = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        boyVelocity.x = boySpeed;
        this->boySprite.setTexture(rightTexture);;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        boyVelocity.x = -boySpeed;
        this->boySprite.setTexture(leftTexture);;
    }
    else
    {
        boyVelocity.x = 0;
    }
}

void Boy::checkBounds()
{

    if (boyPosition.x < 0)
    {
        boyPosition.x = 0;
        boyVelocity.x = 0;
    }
    else if (boyPosition.x > windowWidth - gridSize)
    {
        boyPosition.x = windowWidth - gridSize;
        boyVelocity.x = 0;
    }

    if (boyPosition.y < 0)
    {
        boyPosition.y = 0;
        boyVelocity.y = 0;
    }
    else if (boyPosition.y > windowHeight - gridSize)
    {
        boyPosition.y = windowHeight - gridSize;
        boyVelocity.y = 0;
    }
}

void Boy::update()
{
    handleMovement();
    checkBounds();
    for (int i = 0; i < bombs.size(); ++i) {
        bombs[i]->update();
        if (bombs[i]->elapsedSeconds >= 2){
            delete bombs[i];
            bombs.erase(bombs.begin() + i);
        }
    }
    boyPosition += boyVelocity;
    boySprite.setPosition(boyPosition);
    boySprite.setScale(static_cast<float>(gridSize) / this->rightTexture.getSize().x,
                       static_cast<float>(gridSize) / this->rightTexture.getSize().y);

}
