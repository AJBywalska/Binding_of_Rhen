#ifndef FIRE_H
#define FIRE_H

#include "entity.h"

class Fire : public Entity
{
private:
    sf::FloatRect rect;
    sf::FloatRect box;

public:
    Fire(float x, float y, sf::Texture& texture);
    virtual ~Fire();

    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);
};

#endif // FIRE_H
