#ifndef ENTITY_H
#define ENTITY_H

#include "movement.h"
#include "animation.h"

class Entity
{
protected:
    sf::Sprite sprite;

    Movement* movment;
    Animation* animation;

public:
    Entity();
    virtual ~Entity();

    void  setTexture(sf::Texture& texture);
    void createMovment(const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimation(sf::Texture& texture);

    virtual void setPosition(const float x, const float y);
    virtual void move(const float& deltaTime, const float x, const float y);

    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderTarget* target);
};

#endif // ENTITY_H
