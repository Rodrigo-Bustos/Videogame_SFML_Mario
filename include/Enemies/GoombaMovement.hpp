#pragma once
#include <Enemies/IEnemyMovement.hpp>

class GoombaMovement : public IEnemyMovement{
public:
   void movementX(sf::Rect<float> &hitbox, EnemyStates &state,
                 Direction &facingDir, float dt) override;
   void movementY(sf::Rect<float> &hitbox, EnemyStates &state, float dt) override;
   void changeState(EnemyStates& state) override;
  ~GoombaMovement() = default;

protected:
  sf::Vector2f speed = {100, 0};
  sf::Vector2f lastPosition;
  bool movingHorizontal= false;
  const float gravity = 14;

protected:
   void collisionsX(sf::Rect<float> &hitbox) override;
   void collisionsY(sf::Rect<float> &hitbox) override;
   bool isColliding(sf::Rect<float> &hitbox, Wall &wall) const override;
};