#include "game.h"
#include "manual.h"
#include "boy.h"


Game::Game() :
        numTilesX(windowWidth/gridSize),  // Replace this with your desired number of tiles
        numTilesY(windowHeight/gridSize)   // Replace this with your desired number of tiles
{
    window.create(sf::VideoMode(500, 500), "Game Window");
    window.setFramerateLimit(60);
    loadTextures();
    createSprites();
    boy = new Boy(&window);
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
        // Handle texture loading error
        window.close();
    }

    // Load other textures as needed
}

void Game::createSprites()
{
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(static_cast<float>(gridSize) / backgroundTexture.getSize().x,
                              static_cast<float>(gridSize) / backgroundTexture.getSize().y);

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
            backgroundSprite.setPosition(static_cast<float>(x * gridSize), static_cast<float>(y * gridSize));
            window.draw(backgroundSprite);
        }
    }
    window.draw(boy->getboysprite());
    for (int i = 0; i < boy->bombs.size(); ++i) {
         window.draw(boy->bombs[i]->getbombsprite());
    }


    //boy->render();
    window.display();

}