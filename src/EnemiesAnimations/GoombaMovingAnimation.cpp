#include <EnemiesAnimations/GoombaMovingAnimation.hpp>
GoombaMovingAnimation::GoombaMovingAnimation() {
  index = 0;
  frames = {{{0, 16}, {16, 16}}, {{18, 16}, {16, 16}}};
}

sf::Rect<int> GoombaMovingAnimation::update() {
  if (cicloAnimacion == 13) {
    index++;
    if (index >= frames.size()) {
      index = 0;
    }
    cicloAnimacion = 0;
  } else {
    cicloAnimacion++;
  }
  return frames[index];
}
void GoombaMovingAnimation::reset() {
  cicloAnimacion = 0;
  index = 0;
}