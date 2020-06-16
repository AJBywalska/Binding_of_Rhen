#include "fire.h"

Fire::Fire(float x, float y, sf::Texture &texture)
{
    sprite.setScale(0.75, 0.75);
    setPosition(x, y);

    createMovment(100.f);
    createAnimation(texture);
    createHitbox(sprite, 25, 60, 120, 50);

    animation->addAnimation("idle", 4.f, 0, 0, 7, 0, 220, 240);
}

Fire::~Fire()
{

}

void Fire::updateAnimation(const float &deltaTime)
{
    animation->play("idle", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
}

void Fire::update(const float &deltaTime)
{
    updateAnimation(deltaTime);

    hitbox->update();
}
