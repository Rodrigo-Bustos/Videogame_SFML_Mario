#pragma once
#include "Wall.hpp"
#include <Player/PlayerState.hpp>
#include <SFML/Graphics.hpp>
#include <GlobalEnums.hpp>

class PlayerMovement {
public:
  void movementX(sf::Rect<float> &hitbox, PlayerState &state,
                 Direction &facingDir, float dt);
  void movementY(sf::Rect<float> &hitbox, PlayerState &state, float dt);
  bool isMovingHorizontal();
  void changeState(PlayerState& state);

private:
  sf::Vector2f speed = {0, 0};
  const sf::Vector2f maxSpeed = {250,8};
  const float gravity = 14;
  const float accel = 12000;
  float inputDir = 0;
  sf::Vector2f lastPosition;
  bool movingHorizontal= false;
  bool isGrounded = false;

private:
  void collisionsX(sf::Rect<float> &hitbox);
  void collisionsY(sf::Rect<float> &hitbox);
  bool isColliding(sf::Rect<float> &hitbox, Wall &wall) const;
};