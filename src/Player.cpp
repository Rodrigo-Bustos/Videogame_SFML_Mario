#include <Player.hpp>

Player::Player(sf::Vector2f position, sf::Vector2f size,
               const sf::Texture &texture, sf::IntRect spriteRect)
    : GameObject(position, size, texture, spriteRect) {
  sprite.setOrigin({spriteRect.size.x / 2.f, spriteRect.size.y / 2.f -8});
}

void Player::updateMovement() {

  movement.movementX(hitbox, state, facingDir);
  movement.movementY(hitbox, state);

  if (movement.isMovingHorizontal()) {
    state = PlayerState::Running;
  } else {
    state = PlayerState::Idle;
  }
}

void Player::updateAnimation() {
  if (state == PlayerState::Running) {
    animator.setAnimation(&runAnim);
  } else if (state == PlayerState::Idle) {
    animator.setAnimation(&idleAnim);
  }

  animator.updateAnimation(this->spriteRect);

  if (facingDir == Direction::Left) {
    sprite.setScale({-1.f, 1.f});
  } else {
    sprite.setScale({1.f, 1.f});
  }
}
