
#ifndef P5SFML_GAME_H
#define P5SFML_GAME_H

#include <SFML/Graphics.hpp>
#include "boy.h"
#include "manual.h"
#include "vector"
#include "box.h"


class Game
{
public:
    Game(std::vector<std::vector<char>> map);
    ~Game();

    void run();

private:
    void readmapinfo();
    void loadTextures();
    void createSprites();
    void handleEvents();
    void checkboyandboxescoll();
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
    std::vector<Box*> boxes;
};


#endif //P5SFML_GAME_H
