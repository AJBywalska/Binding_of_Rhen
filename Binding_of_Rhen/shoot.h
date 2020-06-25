#ifndef SHOOT_H
#define SHOOT_H

#include "entity.h"

class Shoot : public Entity
{
public:
    Shoot(float x, float y, sf::Texture &texture);
    virtual ~Shoot();

    const sf::Vector2f &getPosition() const;
    void shooting(const float& x, const float& y);

    void updateAnimation(const float& deltaTime);
    void update(const float& deltaTime);
};

#endif // SHOOT_H
