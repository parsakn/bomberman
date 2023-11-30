#include "game.h"
#include "manual.h"
#include "boy.h"
#include "box.h"


Game::Game(std::vector<std::vector<char>> Gamemap) :
        map(Gamemap)

{
    window.create(sf::VideoMode(windowWidth, windowHeight), "Game Window");
    window.setFramerateLimit(60);
    numTilesX = static_cast<int> (map.size());
    numTilesY = static_cast<int> (map.size());
    tileSize = windowHeight / numTilesX ;
    loadTextures();
    createSprites();
    readmapinfo();
    boy = new Boy(tileSize, boxes);
}

Game::~Game()
{
    delete boy;
}

void Game::readmapinfo() {

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'B'){
                boxes.push_back(new Box(sf::Vector2f(j * tileSize,i * tileSize),1,tileSize));
            }
            if (map[i][j] == 'P'){
                boxes.push_back(new Box(sf::Vector2f(j * tileSize,i * tileSize),2,tileSize));
            }
        }
    }
}

void Game::run()
{
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}

void Game::loadTextures()
{
    if (!backgroundTexture.loadFromFile(BACKGROUNDADD))
    {

        window.close();
    }


}

void Game::createSprites()
{
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(static_cast<float>(tileSize) / backgroundTexture.getSize().x,
                              static_cast<float>(tileSize) / backgroundTexture.getSize().y);

}

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

    }


}

void Game::update()
{
    boy->update();
}

void Game::render()
{
    window.clear();


    for (int x = 0; x < numTilesX; x++)
    {
        for (int y = 0; y < numTilesY; y++)
        {
            backgroundSprite.setPosition(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize));
            window.draw(backgroundSprite);
        }
    }

    for (int i = 0; i < boxes.size(); ++i) {
        boxes[i]->fixsprite();
        window.draw(boxes[i]->get_box_sprite());
    }

    for (auto & bomb : boy->bombs) {
         window.draw(bomb->getbombsprite());
    }

    window.draw(boy->getboysprite());


    window.display();

}