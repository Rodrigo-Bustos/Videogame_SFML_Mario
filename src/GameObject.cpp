#include "GameObject.hpp"

void GameObject::render(sf::RenderWindow& window)
{
    sprite.setTextureRect(spriteRect);

        sf::FloatRect bounds = sprite.getLocalBounds();

    sprite.setOrigin({
        bounds.size.x / 2.f,
        bounds.size.y / 2.f
    });
    sprite.setPosition(hitbox.getCenter());

    window.draw(sprite);
}
GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, const sf::Texture& texture, sf::IntRect spriteRect)
:hitbox(position,size), sprite(texture) , spriteRect(spriteRect)
{};

sf::Vector2f GameObject::getPosition() const { return hitbox.position;}
sf::Vector2f GameObject::getSize() const { return hitbox.size; }