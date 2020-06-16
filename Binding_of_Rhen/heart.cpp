#include "heart.h"

Heart::Heart(float x, float y, sf::Texture &texture)
{
    sprite.setScale(0.75, 0.75);
    setPosition(x, y);

    createMovment(100.f);
    createAnimation(texture);
    createHitbox(sprite, 10, 10, 50, 50);

    animation->addAnimation("idle", 4.f, 0, 0, 9, 0, 100, 85);
}

Heart::~Heart()
{

}

void Heart::updateAnimation(const float &deltaTime)
{
    animation->play("idle", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
}

void Heart::update(const float &deltaTime)
{
    updateAnimation(deltaTime);

    hitbox->update();
}
