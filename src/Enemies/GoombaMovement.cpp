#include <Enemies/GoombaMovement.hpp>

void GoombaMovement::movementX(sf::Rect<float> &hitbox, EnemyStates &state, Direction &facingDir, float dt) {
    hitbox.position.x -= speed.x * dt;
    collisionsX(hitbox);
    lastPosition = hitbox.position;
    
}
void GoombaMovement::movementY(sf::Rect<float> &hitbox, EnemyStates &state, float dt) {
speed.y += gravity*dt;
hitbox.position.y += speed.y;
collisionsY(hitbox);
lastPosition = hitbox.position;
}

void GoombaMovement::changeState(EnemyStates& state) {

}

void GoombaMovement::collisionsX(sf::Rect<float> &hitbox) {
    for (Wall* wall : Wall::getS_Wall()) {
        if (isColliding(hitbox, *wall)){
            bool movingToRight = hitbox.position.x > lastPosition.x;
            if (movingToRight) {
                hitbox.position.x = wall->getPosition().x - hitbox.size.x;
            }
            else {
                hitbox.position.x = wall->getPosition().x + wall->getSize().x;
            }
            speed.x = -speed.x;
        }
    }
}
void GoombaMovement::collisionsY(sf::Rect<float> &hitbox) {
    for (Wall* wall : Wall::getS_Wall()) {
        if (isColliding(hitbox, *wall)){
            bool movingUp = hitbox.position.y < lastPosition.y;
            if (movingUp) {
                hitbox.position.y = wall->getPosition().y + wall->getSize().y;
            }
            else {
                hitbox.position.y = wall->getPosition().y - hitbox.size.y;
                speed.y = 0;
            }
        }
    }
    
}
bool GoombaMovement::isColliding(sf::Rect<float> &hitbox, Wall &wall) const  {
    bool horizontalCollision = (hitbox.position.x + hitbox.size.x > wall.getPosition().x && hitbox.position.x < wall.getPosition().x + wall.getSize().x);
    bool verticalCollision = (hitbox.position.y < wall.getPosition().y + wall.getSize().y && hitbox.position.y +  hitbox.size.y > wall.getPosition().y);
    return horizontalCollision && verticalCollision;
}