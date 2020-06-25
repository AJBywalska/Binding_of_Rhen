#include "boss.h"

Boss::Boss(float x, float y, sf::Texture &texture)
{
    setPosition(x, y);
    GlobalBounds();

    hp = 8;

    createMovment(300.f);
    createAnimation(texture);
    createHitbox(sprite, 230.f, 220.f, 410.f, 540.f);

    animation->addAnimation("idle", 4.f, 0, 0, 15, 0, 900, 900);
}

Boss::~Boss()
{

}

const sf::Vector2f &Boss::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect Boss::GlobalBounds()
{
    rect.top = sprite.getGlobalBounds().top + 230;
    rect.left = sprite.getGlobalBounds().left + 200;
    rect.width = sprite.getGlobalBounds().width - 490;
    rect.height = sprite.getGlobalBounds().height - 360;

    return rect;
}

void Boss::anime(const float &x, const float &y)
{
    sprite.move(x, y);
}

void Boss::updateAnimation(const float &deltaTime)
{
    if(movment->getDirection(didle))
        animation->play("idle", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
}

void Boss::update(const float &deltaTime)
{
    updateAnimation(deltaTime);

    hitbox->update();
}
