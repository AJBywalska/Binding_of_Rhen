#ifndef HEART_H
#define HEART_H

#include "entity.h"

class Heart : public Entity
{
private:
    sf::FloatRect rect;

public:
    Heart(float x, float y, sf::Texture& texture);
    virtual ~Heart();

    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);
};

#endif // HEART_H
