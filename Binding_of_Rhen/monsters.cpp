#include "monsters.h"

Monsters::Monsters(float x, float y, sf::Texture &texture)
{
    setPosition(x, y);

    createMovment(300.f/*, 15.f, 5.f*/);
    createAnimation(texture);
    createHitbox(sprite, 75.f, 70.f, 135.f, 185.f);

    animation->addAnimation("idle", 4.f, 0, 0, 17, 0, 300, 300);
    animation->addAnimation("walk", 3.f, 0, 1, 23, 1, 300, 300);

}

Monsters::~Monsters()
{

}

const sf::Vector2f &Monsters::getPosition() const
{
    return sprite.getPosition();
}

sf::IntRect Monsters::setGlobalBounds()
{
    rect.top = sprite.getGlobalBounds().top + 70;
    rect.left = sprite.getGlobalBounds().left + 75;
    rect.width = sprite.getGlobalBounds().width - 165;
    rect.height = sprite.getGlobalBounds().height - 115;

    return rect;
}

void Monsters::updateAnimation(const float &deltaTime)
{
    if(movment->getDirection(didle))
        animation->play("idle", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    if(movment->getDirection(left) || movment->getDirection(up)){
        sprite.setOrigin(290.f, 0.f);
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
