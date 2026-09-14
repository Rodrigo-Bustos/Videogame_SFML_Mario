#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
  void render(sf::RenderWindow &window);
  GameObject(sf::Vector2f position, sf::Vector2f size,
             const sf::Texture &texture, sf::IntRect spriteRect);
  sf::Vector2f getPosition() const;
  sf::Vector2f getSize() const;

protected:
  sf::Rect<float> hitbox;
  sf::Sprite sprite;
  sf::IntRect spriteRect;
};