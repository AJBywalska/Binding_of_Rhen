#include "entity.h"

Entity::Entity()
{
    movment = nullptr;
    animation = nullptr;
    hitbox = nullptr;
}

Entity::~Entity()
{
    delete movment;
    delete animation;
    delete hitbox;
}

void Entity::createMovment(const float maxVelocity/*, const float acceleration, const float deceleration*/)
{
    movment = new Movement(sprite, maxVelocity/*, acceleration, deceleration*/);
}

void Entity::createAnimation(sf::Texture &texture)
{
    animation = new Animation(sprite, texture);
}

void Entity::createHitbox(sf::Sprite &sprite, float x, float y, float width, float height)
{
    hitbox = new Hitbox(sprite, x, y, width, height);
}

void Entity::setPosition(const float x, const float y)
{
    sprite.setPosition(x,y);
}

void Entity::move(const float x, const float y, const float& deltaTime)
{
    if(movment){
        movment->move(x, y, deltaTime);
    }
}

void Entity::update(const float &deltaTime)
{

}

void Entity::render(sf::RenderTarget& target)
{
    target.draw(sprite);

    if(hitbox)
        hitbox->render(target);
}
