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

void Entity::createMovment(const float maxVelocity)
{
    movment = new Movement(sprite, maxVelocity);
}

void Entity::createAnimation(sf::Texture &texture)
{
    animation = new Animation(sprite, texture);
}

void Entity::createHitbox(sf::Sprite &sprite, float x, float y, float width, float height)
{
    hitbox = new Hitbox(sprite, x, y, width, height);
}

void Entity::loseHP()
{
    hp--;

    if (hp < 0)
        hp = 0;
}

void Entity::gainHP()
{
    hp++;

    if (hp > hpMax)
        hp = hpMax;
}

void Entity::losePoints(int point)
{
    points -= point;
}

void Entity::gainPoints(int point)
{
    points += point;
}

bool Entity::isDead() const
{
    return hp <= 0;
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

void Entity::render(sf::RenderTarget& target)
{
    target.draw(sprite);

    if(hitbox)
        hitbox->render(target);
}
