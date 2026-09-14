#include <PlayerMovement.hpp>
#include "PlayerState.hpp"

void Movement::movementX(sf::Rect<float> &hitbox,  PlayerState& state, Direction& facingDir) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        hitbox.position.x -= speed.x;
        facingDir = Direction::Left;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        hitbox.position.x += speed.x;
        facingDir = Direction::Right;
    }
    collisionsX(hitbox);
    movingHorizontal = (hitbox.position.x != lastPostion.x) ? 1 : 0;
    lastPostion = hitbox.position;
}
void Movement::movementY(sf::Rect<float> &hitbox, PlayerState& state) {
    hitbox.position.y += speed.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        hitbox.position.y -= speed.y*2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        hitbox.position.y += speed.y;
    }
    collisionsY(hitbox);
    lastPostion = hitbox.position;
}

void Movement::collisionsX(sf::Rect<float> &hitbox) {
    for (Wall* wall : Wall::getS_Wall()) {
        if (isColliding(hitbox, *wall)){
            bool movingToRight = hitbox.position.x > lastPostion.x;
            if (movingToRight) {
                hitbox.position.x = wall->getPosition().x - hitbox.size.x;
            }
            else {
                hitbox.position.x = wall->getPosition().x + wall->getSize().x;
            }
        }
    }
}
void Movement::collisionsY(sf::Rect<float> &hitbox) {
    for (Wall* wall : Wall::getS_Wall()) {
        if (isColliding(hitbox, *wall)){
            bool movingUp = hitbox.position.y < lastPostion.y;
            if (movingUp) {
                hitbox.position.y = wall->getPosition().y + wall->getSize().y;
            }
            else {
                hitbox.position.y = wall->getPosition().y - hitbox.size.y;
            }
        }
    }
}

bool Movement::isColliding(sf::Rect<float> &hitbox, Wall &wall) const{
    bool horizontalCollision = (hitbox.position.x + hitbox.size.x > wall.getPosition().x && hitbox.position.x < wall.getPosition().x + wall.getSize().x);
    bool verticalCollision = (hitbox.position.y < wall.getPosition().y + wall.getSize().y && hitbox.position.y +  hitbox.size.y > wall.getPosition().y);
    return horizontalCollision && verticalCollision;
}

bool Movement::isMovingHorizontal()
{
    return movingHorizontal;
}