
#ifndef P5SFML_GAME_H
#define P5SFML_GAME_H

#include <SFML/Graphics.hpp>
#include "boy.h"
#include "manual.h"
#include "vector"


class Game
{
public:
    Game(std::vector<std::vector<char>> map);
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
    int numTilesX;
    int numTilesY;
    int tileSize;
    std::vector<std::vector<char>> map;
};


#endif //P5SFML_GAME_H
