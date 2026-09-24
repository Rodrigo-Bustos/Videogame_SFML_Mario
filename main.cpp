#include "Player/Player.hpp"
#include "Wall.hpp"
#include <Enemies/Goomba.hpp>
#include <SFML/Graphics.hpp>
#include <TextureManager.hpp>

int main() {
  // Create the main window
  sf::RenderWindow window(sf::VideoMode({800, 500}), "Danilito ugu");
  window.setFramerateLimit(120);

  TextureManager textureManager;
  textureManager.loadTexture("Mario", "assets/Mario.png");
  textureManager.loadTexture("Enemies", "assets/enemiesSprites.png");
  textureManager.loadTexture("TileSet", "assets/TileSet.png");

  sf::Vector2f playerStartingPos = {100.f, 70.f};
  sf::Vector2f playerSize = {16.f, 16.f};
  sf::IntRect playerSpriteRect = {{0, 88}, {16, 16}};

  Player Mario(playerStartingPos, playerSize,
               textureManager.getTexture("Mario"), playerSpriteRect);

  sf::IntRect wallSpriteRect = {{0, 16}, {16, 16}};
  sf::Vector2f wallSize = {16.f, 16.f};
  for (int j = 420; j < 436; j += 16) {
    for (int i = 0; i <= 800; i += 16)
      new Wall({static_cast<float>(i), static_cast<float>(j)}, wallSize,
               textureManager.getTexture("TileSet"), wallSpriteRect);
  }

  for (int j = 404; j <=404; j += 16) {
    for (int i = 84; i <= 84; i += 16)
      new Wall({static_cast<float>(i), static_cast<float>(j)}, wallSize,
               textureManager.getTexture("TileSet"), wallSpriteRect);
  }

  Goomba *Goomba1 =
      new Goomba({300, 300}, {16.f, 16.f}, textureManager.getTexture("Enemies"),
                 {{0, 16}, {16, 16}});

  sf::Clock clock;
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }
    float deltaTime = clock.restart().asSeconds();

    Mario.updateMovement(deltaTime);
    Mario.updateAnimation();
    Goomba1->checkIfAlive(deltaTime);
    window.clear(sf::Color(146, 144, 255));

    Mario.render(window);
    Goomba1->render(window);

    for (auto &wall : Wall::getS_Wall()) {
      wall->render(window);
    }

    window.display();
  }
}