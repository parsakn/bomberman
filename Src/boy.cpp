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

void Boy::checkBounds() {

    if (boyPosition.x < 0) {
        boyPosition.x = 0;
        boyVelocity.x = 0;
    } else if (boyPosition.x > windowWidth - tileSize) {
        boyPosition.x = windowWidth - tileSize;
        boyVelocity.x = 0;
    }

    if (boyPosition.y < 0) {
        boyPosition.y = 0;
        boyVelocity.y = 0;
    } else if (boyPosition.y > windowHeight - tileSize) {
        boyPosition.y = windowHeight - tileSize;
        boyVelocity.y = 0;
    }

    for (int i = 0; i < boxes.size(); ++i) {
       sf::FloatRect boy_r = boySprite.getGlobalBounds();
       sf::FloatRect box_r = boxes[i]->get_box_sprite().getGlobalBounds();






        if ((boy_r.left < box_r.left + box_r.width)&&(boy_r.left >= box_r.left + box_r.width - boySpeed) && ((boy_r.top >= box_r.top && boy_r.top <= (box_r.top + box_r.height)) || (boy_r.top + boy_r.height >= box_r.top && boy_r.top + boy_r.height <= box_r.top + box_r.height))){
           if(!(box_r.top == boy_r.top + boy_r.height || box_r.top + box_r.height == boy_r.top)) {
               boyPosition.x = box_r.left + box_r.width;
               boyVelocity.x = 0;
           }
        }
        if ((boy_r.left + boy_r.width > box_r.left )&&(boy_r.left + boy_r.width <= box_r.left + boySpeed) && ((boy_r.top >= box_r.top && boy_r.top <= (box_r.top + box_r.height)) || (boy_r.top + boy_r.height >= box_r.top && boy_r.top + boy_r.height <= box_r.top + box_r.height))){
            if (!(box_r.top == boy_r.top + boy_r.height || box_r.top + box_r.height == boy_r.top)) {
                boyPosition.x = box_r.left - boy_r.width;
                boyVelocity.x = 0;
            }
        }

        //(((boy_r.left <= box_r.left + box_r.width) && (boy_r.left + boy_r.width >= box_r.left)) || ((boy_r.left + boy_r.width <= box_r.left + box_r.width)&&(boy_r.left + boy_r.width >= box_r.left )))

        if ((boy_r.top + boy_r.height > box_r.top) && (boy_r.top + boy_r.height <= box_r.top + boySpeed) && (((boy_r.left <= box_r.left + box_r.width) && (boy_r.left + boy_r.width >= box_r.left)) || ((boy_r.left + boy_r.width <= box_r.left + box_r.width)&&(boy_r.left + boy_r.width >= box_r.left )))){
            if (!(box_r.left == boy_r.left + boy_r.width || box_r.left + box_r.width == boy_r.left)) {
                boyPosition.y = box_r.top - boy_r.height;
                boyVelocity.y = 0;
            }
        }
        if ((boy_r.top < box_r.top + box_r.height) && (boy_r.top >= box_r.top + box_r.height - boySpeed) && (((boy_r.left <= box_r.left + box_r.width) && (boy_r.left + boy_r.width >= box_r.left)) || ((boy_r.left + boy_r.width <= box_r.left + box_r.width)&&(boy_r.left + boy_r.width >= box_r.left )))){
            if (!(box_r.left == boy_r.left + boy_r.width || box_r.left + box_r.width == boy_r.left)) {
                boyPosition.y = box_r.top + box_r.height;
                boyVelocity.y = 0;
            }
        }


    }

}


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
