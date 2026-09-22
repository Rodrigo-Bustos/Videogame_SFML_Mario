#pragma once
#include <SFML/Graphics.hpp>
#include <Animations/IAnimation.hpp>

class Animator {
public:
    void setAnimation(IAnimation* newAnimation);
    void updateAnimation(sf::Rect<int> &spriteRec);
private:
    IAnimation* currentAnimation = nullptr;
};