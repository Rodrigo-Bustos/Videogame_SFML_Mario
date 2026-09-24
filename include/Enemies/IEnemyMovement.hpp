#pragma once
#include "Wall.hpp"
#include <SFML/Graphics.hpp>
#include <Enemies/EnemiesEnums.hpp>
#include <GlobalEnums.hpp>

class IEnemyMovement {
public:
  virtual void movementX(sf::Rect<float> &hitbox, EnemyStates &state,
                 Direction &facingDir, float dt) = 0;
  virtual void movementY(sf::Rect<float> &hitbox, EnemyStates &state, float dt) = 0;
  virtual void changeState(EnemyStates& state) = 0;
  virtual ~IEnemyMovement() = default;

protected:
  sf::Vector2f speed = {0, 0};

protected:
  virtual void collisionsX(sf::Rect<float> &hitbox) = 0;
  virtual void collisionsY(sf::Rect<float> &hitbox) = 0;
  virtual bool isColliding(sf::Rect<float> &hitbox, Wall &wall) const = 0;
};