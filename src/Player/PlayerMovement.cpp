#include <Player/PlayerMovement.hpp>
#include "Player/PlayerState.hpp"

void Movement::movementX(sf::Rect<float> &hitbox,  PlayerState& state, Direction& facingDir, float dt) {
    inputDir = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        inputDir -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        inputDir += 1.f;
    }
    if (inputDir != 0.f) {
        // If pressing opposite direction of current movement, turn around instantly
        if ((inputDir < 0.f && speed.x > 0.f) || (inputDir > 0.f && speed.x < 0.f)) {
            speed.x = 0.f;
        }

        speed.x += inputDir  * dt * accel;
        facingDir = (inputDir < 0.f) ? Direction::Left : Direction::Right;
    } 
    else {
        speed.x = 0.f;
    }

    if (speed.x > maxSpeed.x)  speed.x = maxSpeed.x;
    if (speed.x < -maxSpeed.x) speed.x = -maxSpeed.x;
   
    hitbox.position.x += speed.x * dt;
    collisionsX(hitbox);
    movingHorizontal = (hitbox.position.x != lastPostion.x) ? 1 : 0;

    lastPostion = hitbox.position;
}
void Movement::movementY(sf::Rect<float> &hitbox, PlayerState& state, float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && isGrounded) {
        speed.y -= 3.5;
        isGrounded = false;
    }
    else {
        speed.y += gravity*dt;
    }
    hitbox.position.y += speed.y;
    collisionsY(hitbox);
    if (lastPostion.y < hitbox.position.y) isGrounded = false;
    lastPostion = hitbox.position;
}
void Movement::changeState(PlayerState& state) {
  if (!isGrounded) {
    state = PlayerState::Jumping;
  } else if (!isMovingHorizontal()) {
    state = PlayerState::Running;
  }
  else {
    state = PlayerState::Idle;
  }
}

void Movement::collisionsX(sf::Rect<float> &hitbox) {
    for (Wall* wall : Wall::getS_Wall()) {
        if (isColliding(hitbox, *wall)){
            bool movingToRight = hitbox.position.x > lastPostion.x;
            if (movingToRight) {
                hitbox.position.x = wall->getPosition().x - hitbox.size.x;
            }
            else {
                hitbox.position.x = wall->getPosition().x + wall->getSize().x;
            }
        }
    }
}
void Movement::collisionsY(sf::Rect<float> &hitbox) {
    for (Wall* wall : Wall::getS_Wall()) {
        if (isColliding(hitbox, *wall)){
            bool movingUp = hitbox.position.y < lastPostion.y;
            if (movingUp) {
                hitbox.position.y = wall->getPosition().y + wall->getSize().y;
            }
            else {
                hitbox.position.y = wall->getPosition().y - hitbox.size.y;
                speed.y = 0;
                isGrounded = true;
            }
        }
    }
}

bool Movement::isColliding(sf::Rect<float> &hitbox, Wall &wall) const{
    bool horizontalCollision = (hitbox.position.x + hitbox.size.x > wall.getPosition().x && hitbox.position.x < wall.getPosition().x + wall.getSize().x);
    bool verticalCollision = (hitbox.position.y < wall.getPosition().y + wall.getSize().y && hitbox.position.y +  hitbox.size.y > wall.getPosition().y);
    return horizontalCollision && verticalCollision;
}

bool Movement::isMovingHorizontal() {
    return movingHorizontal;
}