#include "heart.h"

Heart::Heart(float x, float y, sf::Texture &texture)
{
    sprite.setScale(0.75, 0.75);
    setPosition(x, y);
    GlobalBounds();

    createMovment(100.f);
    createAnimation(texture);

    animation->addAnimation("idle", 4.f, 0, 0, 9, 0, 100, 85);
}

Heart::~Heart()
{

}

sf::FloatRect Heart::GlobalBounds()
{
    rect.top = sprite.getGlobalBounds().top - 9;
    rect.left = sprite.getGlobalBounds().left - 9;
    rect.width = sprite.getGlobalBounds().width - 15;
    rect.height = sprite.getGlobalBounds().height - 10;

    return rect;
}

void Heart::updateAnimation(const float &deltaTime)
{
    animation->play("idle", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
}

void Heart::update(const float &deltaTime)
{
    updateAnimation(deltaTime);
}
