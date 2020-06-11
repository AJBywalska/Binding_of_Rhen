#include "player.h"

void Player::initComponents()
{

}

Player::Player(float x, float y, sf::Texture& texture)
{
    setPosition(x, y);
    setGlobalBounds();

    attacking = false;

    createMovment(300.f/*, 15.f, 5.f*/);
    createAnimation(texture);
    createHitbox(sprite, 85.f, 60.f, 130.f, 175.f);

    animation->addAnimation("idleFront", 3.f, 0, 0, 29, 0, 300, 300);
    animation->addAnimation("walkDown", 6.f, 0, 1, 29, 1, 300, 300);
    animation->addAnimation("walkRight", 6.f, 0, 2, 29, 2, 300, 300);
    animation->addAnimation("walkLeft", 6.f, 0, 3, 29, 3, 300, 300);
    animation->addAnimation("walkUp", 6.f, 0, 4, 29, 4, 300, 300);
    animation->addAnimation("attackDown", 1.f, 0, 5, 14, 5, 300, 300);
    animation->addAnimation("attackRight", 2.f, 0, 6, 14, 6, 300, 300);
    animation->addAnimation("attackLeft", 2.f, 0, 7, 14, 7, 300, 300);
    animation->addAnimation("attackUp", 1.f, 0, 8, 14, 8, 300, 300);
}

Player::~Player()
{

}

const sf::Vector2f &Player::getPosition() const
{
    return sprite.getPosition();
}

sf::IntRect Player::setGlobalBounds()
{
    rect.top = sprite.getGlobalBounds().top + 60;
    rect.left = sprite.getGlobalBounds().left + 85;
    rect.width = sprite.getGlobalBounds().width - 170;
    rect.height = sprite.getGlobalBounds().height - 125;

    return rect;
}

void Player::updateAttack()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        attacking = true;
}

void Player::updateAnimation(const float &deltaTime)
{
    if(attacking){
        if(movment->getDirection(down))
            if(animation->play("attackDown", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
        if(movment->getDirection(up))
            if(animation->play("attackUp", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
        if(movment->getDirection(left))
            if(animation->play("attackLeft", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
        if(movment->getDirection(right))
            if(animation->play("attackRight", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
    }

    else if(movment->getVelocity().x == 0.f && movment->getVelocity().y == 0.f)
        animation->play("idleFront", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    else if(movment->getDirection(left))
        animation->play("walkLeft", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    else if(movment->getDirection(right))
        animation->play("walkRight", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    else if(movment->getDirection(up))
        animation->play("walkUp", deltaTime, movment->getVelocity().y, movment->getMaxVelocity());
    else if(movment->getDirection(down))
        animation->play("walkDown", deltaTime, movment->getVelocity().y, movment->getMaxVelocity());
}

void Player::update(const float &deltaTime)
{
    movment->update(deltaTime);
    updateAttack();
    updateAnimation(deltaTime);


    hitbox->update();
}

