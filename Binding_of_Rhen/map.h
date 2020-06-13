#ifndef MAP_H
#define MAP_H

#include "entity.h"

class Map : public Entity
{
private:
    sf::IntRect rect;

public:
    Map(float x, float y, sf::Texture& texture);
    virtual ~Map();

    sf::IntRect setGlobalBounds();
    void updateAnimation(const float &deltaTime);
    virtual void update(const float& deltaTime);
};

#endif // MAP_H
