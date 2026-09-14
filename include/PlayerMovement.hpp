#pragma once
#include "Wall.hpp"
#include <PlayerState.hpp>
#include <SFML/Graphics.hpp>

class Movement {
public:
  void movementX(sf::Rect<float> &hitbox, PlayerState &state,
                 Direction &facingDir);
  void movementY(sf::Rect<float> &hitbox, PlayerState &state);
  bool isMovingHorizontal();

private:
  const sf::Vector2f speed = {2, 2};
  sf::Vector2f lastPostion;
  bool movingHorizontal;

private:
  void collisionsX(sf::Rect<float> &hitbox);
  void collisionsY(sf::Rect<float> &hitbox);
  bool isColliding(sf::Rect<float> &hitbox, Wall &wall) const;
};