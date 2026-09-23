#include <SFML/Graphics.hpp>
#include "Player/Player.hpp"
#include <TextureManager.hpp>
#include "Wall.hpp"
 
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Danilito ugu");
    window.setFramerateLimit(120);

    TextureManager textureManager;
    textureManager.loadTexture("Mario", "assets/Mario.png");
    textureManager.loadTexture("Wall", "assets/wallTexture.png");
    
    sf::Vector2f playerStartingPos = {100.f, 70.f};
    sf::Vector2f playerSize = {16.f, 16.f};
    sf::IntRect playerSpriteRect = {{0,88},{16,16}};

    Player Mario(
        playerStartingPos, 
        playerSize, 
        textureManager.getTexture("Mario"), 
        playerSpriteRect);


    sf::IntRect wallSpriteRect = {{0,88},{16,16}};
    sf::Vector2f wallSize = {16.f, 16.f};
    
    for (int i = 0 ; i <= 800; i += 16)
        new Wall({static_cast<float>(i),200}, 
    wallSize, 
    textureManager.getTexture("Wall"), 
    wallSpriteRect);
    

    sf::Clock clock;
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        float deltaTime = clock.restart().asSeconds();
        
        Mario.updateMovement(deltaTime);
        Mario.updateAnimation();
        window.clear(sf::Color(146, 144, 255));

        Mario.render(window);
        
        for(auto& wall : Wall::getS_Wall()){
            wall ->render(window);
        }

        window.display();
    }
}