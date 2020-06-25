#include "shoot.h"

Shoot::Shoot(float x, float y, sf::Texture &texture)
{
    setPosition(x, y);

    createAnimation(texture);
    createHitbox(sprite, 7.f, 8.f, 32.f, 32.f);

    animation->addAnimation("idle", 4.f, 0, 0, 0, 0, 76, 70);
}

Shoot::~Shoot()
{

}

const sf::Vector2f &Shoot::getPosition() const
{
    return sprite.getPosition();
}

void Shoot::shooting(const float& x, const float& y)
{
    sprite.move(x, y);
}

void Shoot::update(const float &deltaTime)
{
    hitbox->update();
}
