#pragma once

#include <Animations/IAnimation.hpp>

class IdleAnimation : public IAnimation {
public:
  sf::Rect<int> update() override;
  void reset() override;
  IdleAnimation() = default;
  

};