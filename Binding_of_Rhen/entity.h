#ifndef ENTITY_H
#define ENTITY_H

#include "movement.h"
#include "animation.h"
#include "hitbox.h"

class Entity
{
protected:
    sf::Sprite sprite;

    Movement* movment;
    Animation* animation;
    Hitbox* hitbox;

    int hp;
    int hpMax = 3;

public:
    Entity();
    virtual ~Entity();

    void createMovment(const float maxVelocity/*, const float acceleration, const float deceleration*/);
    void createAnimation(sf::Texture& texture);
    void createHitbox(sf::Sprite& sprite, float x, float y, float width, float height);

    void loseHP();
    void gainHP(const int hp);

    const bool isDead() const;

    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float& deltaTime);

    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderTarget& target);
};

#endif // ENTITY_H
