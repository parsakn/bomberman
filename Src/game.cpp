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
    boy = new Boy(tileSize);
}

Game::~Game()
{
    delete boy;
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

    for (auto & bomb : boy->bombs) {
         window.draw(bomb->getbombsprite());
    }

    window.draw(boy->getboysprite());


    window.display();

}