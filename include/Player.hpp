#pragma once
#include "Animator.hpp"
#include "GameObject.hpp"
#include <PlayerMovement.hpp>
#include <PlayerState.hpp>
#include <RunningAnimation.hpp>
#include <IdleAnimation.hpp>

class Player : public GameObject {
public:
  Player(sf::Vector2f position, sf::Vector2f size, const sf::Texture &texture,
         sf::IntRect spriteRect);
  void updateMovement(float dt);
  void updateAnimation();

private:
  Animator animator;
  Movement movement;

  PlayerState state = PlayerState::Idle;
  Direction facingDir = Direction::Right;

  RunningAnimation runAnim;
  IdleAnimation idleAnim;
};
