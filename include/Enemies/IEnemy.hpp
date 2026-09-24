#pragma once
#include <GameObject.hpp>
#include <Animator.hpp>
#include <GlobalEnums.hpp>
#include <SFML/Graphics.hpp>
#include <Player/Player.hpp>
#include <Enemies/EnemiesEnums.hpp>

class IEnemy : public GameObject {
public:
    IEnemy(sf::Vector2f position, sf::Vector2f size, const sf::Texture &texture,
         sf::IntRect spriteRect);
    virtual void enemyMovement(float dt) = 0;
    virtual void checkIfAlive(float dt) = 0;
    void spawnEnemy(/*Camera Class*/);
    virtual ~IEnemy() = default;
protected:
    Direction facingDir = Direction::Right;
    bool isAlive = true;
    bool hasSpawned = true; //Change to false when spawnEnemy function is ready
    EnemyStates state = EnemyStates::moving;
    
    Animator animator;
};