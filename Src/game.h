
#ifndef P5SFML_GAME_H
#define P5SFML_GAME_H

#include <SFML/Graphics.hpp>
#include "boy.h"
#include "manual.h"


class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void loadTextures();
    void createSprites();
    void handleEvents();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Boy* boy;
    const int numTilesX;
    const int numTilesY;
};


#endif //P5SFML_GAME_H
