#include "movement.h"

Movement::Movement(sf::Sprite& sprite, float maxVelocity)
    : sprite(sprite), maxVelocity(maxVelocity)
{
    this->maxVelocity = maxVelocity;
}

Movement::~Movement()
{

}

const float &Movement::getMaxVelocity() const
{
    return maxVelocity;
}

const sf::Vector2f &Movement::getVelocity() const
{
    return velocity;
}

bool Movement::getDirection(const unsigned short state) const
{
    switch (state) {
    case didle:
        if(velocity.x == 0.f && velocity.y == 0.f)
            return true;
        break;
    case up:
        if(velocity.y < 0.f)
            return true;
        break;

    case down:
        if(velocity.y > 0.f)
                return true;
        break;

    case moving:
        if(velocity.x != 0.f || velocity.y != 0.f)
            return true;
        break;

    case left:
        if(velocity.x < 0.f)
            return true;
        break;

    case right:
        if(velocity.x > 0.f)
            return true;
        break;


    }
    return false;
}

void Movement::move(const float x, const float y, const float& deltaTime)
{
    velocity.x = maxVelocity * x;
    velocity.y = maxVelocity * y;

    sprite.move(velocity * deltaTime);
}

