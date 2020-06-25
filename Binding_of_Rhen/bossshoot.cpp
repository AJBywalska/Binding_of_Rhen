#include "bossshoot.h"

BossShoot::BossShoot(float x, float y, sf::Texture &texture)
{
    setPosition(x, y);

    createAnimation(texture);
    createHitbox(sprite, 20.f, 25.f, 100.f, 100.f);

    animation->addAnimation("idle", 4.f, 0, 0, 0, 0, 200, 200);
}

BossShoot::~BossShoot()
{

}

const sf::Vector2f &BossShoot::getPosition() const
{
    return sprite.getPosition();
}

void BossShoot::shooting(const float& x, const float& y)
{
    sprite.move(x, y);
}

void BossShoot::update(const float &deltaTime)
{
    hitbox->update();
}
