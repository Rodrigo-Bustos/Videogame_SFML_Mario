#include "Enemies/EnemiesEnums.hpp"
#include "Enemies/IEnemy.hpp"
#include <Enemies/Goomba.hpp>
Goomba::Goomba(sf::Vector2f position, sf::Vector2f size,
               const sf::Texture &texture, sf::IntRect spriteRect)
    : IEnemy(position, size, texture, spriteRect) {}

void Goomba::enemyMovement(float dt) {
 if (hasSpawned) {
    
    movement.movementY(hitbox, state, dt);
    movement.movementX(hitbox, state, facingDir, dt);
 }
}

void Goomba::checkIfAlive(float dt) {
    if (isAlive) {
        enemyMovement(dt);
    }
    else {
        return;
    }
    // animator.setAnimation(IAnimation *newAnimation) 
    // animator.updateAnimation(sf::Rect<int> &spriteRec)
}

void Goomba::wasSteppedOn() {
    state = EnemyStates::dead;
    isAlive = false;
}