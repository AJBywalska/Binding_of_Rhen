#ifndef ENTITY_H
#define ENTITY_H

#include "movement.h"
#include "animation.h"
#include "hitbox.h"

class Entity : public sf::Sprite
{
protected:
    sf::Sprite sprite;

    Movement* movment;
    Animation* animation;

    int hpMax = 6;

public:
    Hitbox* hitbox;
    int hp;

    Entity();
    virtual ~Entity();

    void createMovment(const float maxVelocity/*, const float acceleration, const float deceleration*/);
    void createAnimation(sf::Texture& texture);
    void createHitbox(sf::Sprite& sprite, float x, float y, float width, float height);

    void loseHP();
    void gainHP();

    bool isDead() const;

    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float& deltaTime);

    virtual void render(sf::RenderTarget& target);
};

#endif // ENTITY_H
