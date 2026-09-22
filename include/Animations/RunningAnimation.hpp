#pragma once

#include <Animations/IAnimation.hpp>
#include <vector>

class RunningAnimation : public IAnimation {
public:
  sf::Rect<int> update() override;
  void reset() override;
  RunningAnimation();
  
  
protected:
  unsigned int cicloCorrer;
  std::vector<sf::Rect<int>> frames;
  unsigned int index;
};