#include "Animator.hpp"
#include <PlayerAnimations/RunningAnimation.hpp>


void Animator::setAnimation(IAnimation* newAnimation) {
    if (currentAnimation != newAnimation) {
        currentAnimation = newAnimation;
        if (currentAnimation) {
            currentAnimation->reset(); 
        }
    }
}

void Animator::updateAnimation(sf::Rect<int> &spriteRec) {
    if (currentAnimation) {
        spriteRec = currentAnimation->update(); 
    }
}