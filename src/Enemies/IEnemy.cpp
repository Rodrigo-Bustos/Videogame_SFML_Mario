#include "GameObject.hpp"
#include <Enemies/IEnemy.hpp>


IEnemy::IEnemy(sf::Vector2f position, sf::Vector2f size,
               const sf::Texture &texture, sf::IntRect spriteRect)
    : GameObject(position, size, texture, spriteRect) {}