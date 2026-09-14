#pragma once
#include "GameObject.hpp"
#include <vector>

class Wall : public GameObject {
public:
  Wall(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texture, sf::IntRect spriteRect);
  static const std::vector<Wall *> &getS_Wall();

private:
  inline static std::vector<Wall *> s_wall;
};