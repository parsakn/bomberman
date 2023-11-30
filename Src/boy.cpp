#include "boy.h"
#include "manual.h"


Boy::Boy(float tilesSize,std::vector<Box*> boxes_b) :
        tileSize(tilesSize),
        boySpeed(2.0f),
        boyVelocity(0, 0),
        boyPosition(0, 0)


{
    boxes = boxes_b;
    downTexture.loadFromFile(BOYDOWNMOVEADD);
    upTexture.loadFromFile(BOYUPMOVEADD);
    rightTexture.loadFromFile(BOYRIGHTMOVEADD);
    leftTexture.loadFromFile(BOYLEFTMOVEADD);
    boySprite.setTexture(downTexture);
}


sf::Vector2f Boy::bombposfixer(sf::Vector2f boyposition){
    boyposition.x = boyposition.x + (tileSize/2);
    boyposition.y = boyposition.y + (tileSize/2);
    float bombpositionx = boyposition.x - ( static_cast<int>(boyposition.x) % static_cast<int>(tileSize) );
    float bombpositiony = boyposition.y - ( static_cast<int>(boyposition.y) % static_cast<int>(tileSize) );

    return sf::Vector2f(bombpositionx,bombpositiony);


}

sf::Sprite Boy::getboysprite(){
    return boySprite;
}

void Boy::handleMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {

        bombs.push_back(new Bomb(bombposfixer(boyPosition),tileSize));
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
    else if (boyPosition.x > windowWidth - tileSize)
    {
        boyPosition.x = windowWidth - tileSize;
        boyVelocity.x = 0;
    }

    if (boyPosition.y < 0)
    {
        boyPosition.y = 0;
        boyVelocity.y = 0;
    }
    else if (boyPosition.y > windowHeight - tileSize)
    {
        boyPosition.y = windowHeight - tileSize;
        boyVelocity.y = 0;
    }

    for (const auto& box : boxes) {
        // Assuming each box has position and size properties
        float boxLeft = box->get_box_position().x;
        float boxRight = box->get_box_position().x + tileSize;
        float boxTop = box->get_box_position().y;
        float boxBottom = box->get_box_position().y + tileSize;

        float overlapX = std::min(boyPosition.x + tileSize, boxRight) - std::max(boyPosition.x, boxLeft);
        float overlapY = std::min(boyPosition.y + tileSize, boxBottom) - std::max(boyPosition.y, boxTop);


        if (boyPosition.x < boxRight && boyPosition.x + tileSize > boxLeft &&
            boyPosition.y < boxBottom && boyPosition.y + tileSize > boxTop) {
            // Collision with a box, prevent boy from moving into it
            if (overlapX < overlapY)
            {
                // Resolve in the X direction
                if (boyVelocity.x > 0)
                {
                    boyPosition.x = boxLeft - tileSize -1.5;
                }
                else if (boyVelocity.x < 0)
                {
                    boyPosition.x = boxRight + 1.5;
                }
                boyVelocity.x = 0;
            }
            else
            {
                // Resolve in the Y direction
                if (boyVelocity.y > 0)
                {
                    boyPosition.y = boxTop - tileSize - 1.5;
                }
                else if (boyVelocity.y < 0)
                {
                    boyPosition.y = boxBottom + 1.5;
                }
                boyVelocity.y = 0;
            }
    }}}


void Boy::update() {
      handleMovement();
      checkBounds();
            for (int i = 0; i < bombs.size(); ++i) {
                bombs[i]->update();
                if (bombs[i]->elapsedSeconds >= 2) {
                    delete bombs[i];
                    bombs.erase(bombs.begin() + i);
                }
            }

            boyPosition += sf::Vector2f(static_cast<float>(boyVelocity.x), static_cast<int>(boyVelocity.y));

            boySprite.setPosition(boyPosition);
            boySprite.setScale(static_cast<float>(tileSize) / this->rightTexture.getSize().x,
                               static_cast<float>(tileSize) / this->rightTexture.getSize().y);

}
