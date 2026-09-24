#pragma once
#include "Enemies/GoombaMovement.hpp"
#include <Enemies/IEnemy.hpp>
#include <Player/Player.hpp>

class Goomba : public IEnemy{
public:
    Goomba(sf::Vector2f position, sf::Vector2f size, const sf::Texture &texture, sf::IntRect spriteRect);
    void checkIfAlive(float dt) override;
    void enemyMovement(float dt) override;
    void wasSteppedOn();
    ~Goomba() = default;
protected:
    GoombaMovement movement;
};