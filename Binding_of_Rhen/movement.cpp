#include "movement.h"

Movement::Movement(sf::Sprite& sprite, float maxVelocity/*, float acceleration, float deceleration*/)
    : sprite(sprite), maxVelocity(maxVelocity)/*, acceleration_(acceleration), deceleration_(deceleration)*/
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

const bool Movement::getDirection(const unsigned short state) const
{
    switch (state) {
    case didle:
        if(velocity.x == 0.f && velocity.y == 0.f)
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

    case up:
        if(velocity.y < 0.f)
            return true;
        break;

    case down:
        if(velocity.y > 0.f)
                return true;
        break;
    }
    return false;
}

void Movement::move(const float x, const float y, const float& deltaTime)
{
//    velocity.x += acceleration_ * x;
//    velocity.y += acceleration_ * y;

    velocity.x = maxVelocity * x;
    velocity.y = maxVelocity * y;
    sprite.move(velocity * deltaTime);
}

void Movement::update(const float &deltaTime)
{
//    if(velocity.x > 0.f){
//        if(velocity.x > maxVelocity)
//            velocity.x = maxVelocity;

//        velocity.x -= deceleration_;
//        if(velocity.x < 0.f)
//            velocity.x = 0.f;
//    }
//    else if(velocity.x < 0.f){

//        if(velocity.x < -maxVelocity)
//            velocity.x = -maxVelocity;

//        velocity.x += deceleration_;
//        if(velocity.x > 0.f)
//            velocity.x = 0.f;
//    }

//    if(velocity.y > 0.f){
//        if(velocity.y > maxVelocity)
//            velocity.y = maxVelocity;

//        velocity.y -= deceleration_;
//        if(velocity.y < 0.f)
//            velocity.y = 0.f;
//    }
//    else if(velocity.y < 0.f){
//        if(velocity.y < -maxVelocity)
//            velocity.y = -maxVelocity;

//        velocity.y += deceleration_;
//        if(velocity.y > 0.f)
//            velocity.y = 0.f;
//    }

//    sprite.move(velocity * deltaTime);
}

