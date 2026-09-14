#include "Wall.hpp"
#include "GameObject.hpp"

Wall::Wall(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texture, sf::IntRect spriteRect)
    : GameObject(position, size, texture, spriteRect) {
        s_wall.push_back(this);
    }
const std::vector<Wall *>& Wall::getS_Wall() { return s_wall; }

