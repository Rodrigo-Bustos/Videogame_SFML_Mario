#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class IAnimation{
public:
    virtual sf::Rect<int> update() = 0;
    virtual void reset() = 0;
    virtual ~IAnimation() = default;
protected:
std::vector<sf::IntRect> frames;
int index;

};