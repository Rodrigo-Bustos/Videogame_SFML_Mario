#include <RunningAnimation.hpp>
#include <PlayerState.hpp>

RunningAnimation::RunningAnimation()
: index(1){
    frames = {{{20,8},{16,16}},{{38,8},{16,16}},{{56,8},{16,16}}};
}

void RunningAnimation::reset() {
    index = 1; 
    cicloCorrer = 0; 
}

sf::Rect<int> RunningAnimation::update(){

    if (cicloCorrer == 15) {
      index++;
      if (index >= 3) {
        index=0;
      }
      cicloCorrer = 0;
    } else {
      cicloCorrer++;
    }
    return frames[index];
  
}