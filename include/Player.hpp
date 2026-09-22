#pragma once
#include "Animations/IAnimation.hpp"
#include "Animations/JumpAnimation.hpp"
#include "Animator.hpp"
#include "GameObject.hpp"
#include <PlayerMovement.hpp>
#include <PlayerState.hpp>
#include <Animations/RunningAnimation.hpp>
#include <Animations/IdleAnimation.hpp>
#include <vector>

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
  JumpAnimation jumpAnim;
  std::vector<IAnimation*> animations = {&runAnim, &idleAnim, &jumpAnim};
};
