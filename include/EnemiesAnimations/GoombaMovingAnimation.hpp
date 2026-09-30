#pragma once
#include <IAnimation.hpp>

class GoombaMovingAnimation : public IAnimation {
public:
  sf::Rect<int> update() override;
  void reset() override;
  GoombaMovingAnimation();
private:
  unsigned int cicloAnimacion;
};