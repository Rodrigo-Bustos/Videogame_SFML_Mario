#include <PlayerAnimations/JumpAnimation.hpp>

sf::Rect<int> JumpAnimation::update() {
    return {{96,8},{16,16}};
}

void JumpAnimation::reset() {}