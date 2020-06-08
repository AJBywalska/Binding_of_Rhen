#include "player.h"

void Player::initComponents()
{

}

Player::Player(float x, float y, sf::Texture& texture)
{
    setPosition(x, y);
    attacking = false;

    createMovment(300.f/*, 15.f, 5.f*/);
    createAnimation(texture);
    createHitbox(sprite, 115.f, 80.f, 170.f, 240.f);

    animation->addAnimation("idleFront", 3.f, 0, 0, 29, 0, 400, 400);
    animation->addAnimation("walkDown", 6.f, 0, 1, 29, 1, 400, 400);
    animation->addAnimation("walkRight", 6.f, 0, 2, 29, 2, 400, 400);
    animation->addAnimation("walkLeft", 6.f, 0, 3, 29, 3, 400, 400);
    animation->addAnimation("walkUp", 6.f, 0, 4, 29, 4, 400, 400);
    animation->addAnimation("attackDown", 10.f, 0, 5, 14, 5, 400, 400);
    animation->addAnimation("attackRight", 10.f, 0, 6, 14, 6, 400, 400);
    animation->addAnimation("attackLeft", 10.f, 0, 7, 14, 7, 400, 400);
    animation->addAnimation("attackUp", 10.f, 0, 8, 14, 8, 400, 400);
}

Player::~Player()
{

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
            if(animation->play("attackDown", deltaTime, true))
                attacking = false;
        if(movment->getDirection(up))
            if(animation->play("attackUp", deltaTime, true))
                attacking = false;
        if(movment->getDirection(left))
            if(animation->play("attackLeft", deltaTime, true))
                attacking = false;
        if(movment->getDirection(right))
            if(animation->play("attackRight", deltaTime, true))
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

