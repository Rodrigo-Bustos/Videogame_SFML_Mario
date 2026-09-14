#include "GameObject.hpp"

void GameObject::render(sf::RenderWindow &window) {
    sprite.setTextureRect(spriteRect);
    sprite.setPosition(hitbox.position);
    window.draw(sprite);
}
GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texture, sf::IntRect spriteRect)
:hitbox(position,size), sprite(texture) , spriteRect(spriteRect)
{};

sf::Vector2f GameObject::getPosition() const { return hitbox.position;}
sf::Vector2f GameObject::getSize() const { return hitbox.size; }