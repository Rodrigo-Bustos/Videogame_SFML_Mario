#include <Player/Player.hpp>

Player::Player(sf::Vector2f position, sf::Vector2f size,
               const sf::Texture &texture, sf::IntRect spriteRect)
    : GameObject(position, size, texture, spriteRect) {
}

void Player::updateMovement(float dt) {

  movement.movementX(hitbox, state, facingDir, dt);
  movement.movementY(hitbox, state, dt);
  movement.changeState(state);

}

void Player::updateAnimation() {
  animator.setAnimation(animations[static_cast<int>(state)]);

  animator.updateAnimation(this->spriteRect);

  if (facingDir == Direction::Left) {
    sprite.setScale({-1.f, 1.f});
  } else {
    sprite.setScale({1.f, 1.f});
  }

}
