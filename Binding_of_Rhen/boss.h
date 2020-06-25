#ifndef BOSS_H
#define BOSS_H

#include "entity.h"

class Boss : public Entity
{
private:
    sf::FloatRect rect;

public:
    Boss(float x, float y, sf::Texture& texture);
    virtual ~Boss();

    const sf::Vector2f &getPosition() const;
    sf::FloatRect GlobalBounds();

    void anime(const float& x, const float& y);

    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);
};

#endif // BOSS_H
