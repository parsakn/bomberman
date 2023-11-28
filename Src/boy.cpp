#include "boy.h"
#include "manual.h"


Boy::Boy(sf::RenderWindow* window) :
        mainWindow(window),
        boySpeed(0.1f),
        boyVelocity(0, 0),
        boyPosition(0, 0)


{
    downTexture.loadFromFile(BOYDOWNMOVEADD);
    upTexture.loadFromFile(BOYUPMOVEADD);
    rightTexture.loadFromFile(BOYRIGHTMOVEADD);
    leftTexture.loadFromFile(BOYLEFTMOVEADD);
    boySprite.setTexture(downTexture);
}


void Boy::handleMovement()
{
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
    //parsakn
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
    boyPosition += boyVelocity;
    boySprite.setPosition(boyPosition);
}

void Boy::render()
{
    boySprite.setScale(static_cast<float>(gridSize) / this->rightTexture.getSize().x,
                       static_cast<float>(gridSize) / this->rightTexture.getSize().y);
    boySprite.setPosition(boyPosition);
    mainWindow->draw(boySprite);
}