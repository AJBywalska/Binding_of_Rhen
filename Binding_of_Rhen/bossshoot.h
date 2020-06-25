#ifndef BOSSSHOOT_H
#define BOSSSHOOT_H

#include "entity.h"

class BossShoot : public Entity
{
public:
    BossShoot(float x, float y, sf::Texture &texture);
    virtual ~BossShoot();

    const sf::Vector2f &getPosition() const;
    void shooting(const float& x, const float& y);

    void update(const float& deltaTime);
};

#endif // BOSSSHOOT_H
