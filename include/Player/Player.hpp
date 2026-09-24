#pragma once
#include "IAnimation.hpp"
#include "PlayerAnimations/JumpAnimation.hpp"
#include "Animator.hpp"
#include "GameObject.hpp"
#include <GlobalEnums.hpp>
#include <Player/PlayerMovement.hpp>
#include <Player/PlayerState.hpp>
#include <PlayerAnimations/RunningAnimation.hpp>
#include <PlayerAnimations/IdleAnimation.hpp>
#include <vector>

class Player : public GameObject {
public:
  Player(sf::Vector2f position, sf::Vector2f size, const sf::Texture &texture,
         sf::IntRect spriteRect);
  void updateMovement(float dt);
  void updateAnimation();

private:
  Animator animator;
  PlayerMovement movement;

  PlayerState state = PlayerState::Idle;
  Direction facingDir = Direction::Right;
 
  
  RunningAnimation runAnim;
  IdleAnimation idleAnim;
  JumpAnimation jumpAnim;
  std::vector<IAnimation*> animations = {&runAnim, &idleAnim, &jumpAnim};
};
