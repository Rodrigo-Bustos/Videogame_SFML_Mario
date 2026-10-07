#pragma once
#include <IAnimation.hpp>

class RunningAnimation : public IAnimation {
public:
  sf::Rect<int> update() override;
  void reset() override;
  RunningAnimation();
  
  
protected:
  unsigned int cicloCorrer;
};