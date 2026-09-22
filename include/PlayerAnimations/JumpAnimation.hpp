#pragma once
#include <SFML/Graphics.hpp>
#include <IAnimation.hpp>

class JumpAnimation : public IAnimation {
public:
  sf::Rect<int> update() override;
  void reset() override;
  JumpAnimation() = default;
  

};