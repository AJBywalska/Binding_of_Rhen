#include "player.h"

void Player::initComponents()
{

}

Player::Player(float x, float y, sf::Texture& texture)
{
    setPosition(x, y);

    createMovment(300.f, 20.f, 10.f);
    createAnimation(texture);

    animation->addAnimation("idleFront", 10.f, 0, 0, 29, 0, 400, 400);
    animation->addAnimation("walkDown", 10.f, 0, 1, 29, 1, 400, 400);
    animation->addAnimation("walkRight", 10.f, 0, 2, 29, 2, 400, 400);
    animation->addAnimation("walkLeft", 10.f, 0, 3, 29, 3, 400, 400);
    animation->addAnimation("walkUp", 10.f, 0, 4, 29, 4, 400, 400);
}

Player::~Player()
{

}

void Player::update(const float &deltaTime)
{
    movment->update(deltaTime);

    if(movment->getDirection(didle))
        animation->play("idleFront", deltaTime);
    else if(movment->getDirection(left))
        animation->play("walkLeft", deltaTime);
    else if(movment->getDirection(right))
        animation->play("walkRight", deltaTime);
    else if(movment->getDirection(up))
        animation->play("walkUp", deltaTime);
    else if(movment->getDirection(down))
        animation->play("walkDown", deltaTime);
}

