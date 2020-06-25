#include "monsters.h"

Monsters::Monsters(float x, float y, sf::Texture &texture)
{
    setPosition(x, y);
    GlobalBounds();

    hp = 3;

    createMovment(300.f);
    createAnimation(texture);
    createHitbox(sprite, 60.f, 60.f, 115.f, 150.f);

    animation->addAnimation("idle", 4.f, 0, 0, 17, 0, 250, 250);
    animation->addAnimation("walk", 3.f, 0, 1, 23, 1, 250, 250);

}

Monsters::~Monsters()
{

}

const sf::Vector2f &Monsters::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect Monsters::GlobalBounds()
{
    rect.top = sprite.getGlobalBounds().top + 60;
    rect.left = sprite.getGlobalBounds().left + 60;
    rect.width = sprite.getGlobalBounds().width - 135;
    rect.height = sprite.getGlobalBounds().height - 100;

    return rect;
}

void Monsters::anime(const float& x, const float& y)
{
    sprite.move(x, y);
}

void Monsters::updateAnimation(const float &deltaTime)
{
    if(movment->getDirection(didle))
        animation->play("idle", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    if(movment->getDirection(left) || movment->getDirection(up)){
        sprite.setOrigin(240.f, 0.f);
        sprite.setScale(-1.f, 1.f);
        animation->play("walk", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    }
    if(movment->getDirection(right) || movment->getDirection(down)){
        sprite.setOrigin(0.f, 0.f);
        sprite.setScale(1.f, 1.f);
        animation->play("walk", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    }
}

void Monsters::update(const float &deltaTime)
{
    updateAnimation(deltaTime);

    hitbox->update();
}
