#ifndef MONSTERS_H
#define MONSTERS_H

#include "entity.h"

class Monsters : public Entity
{
private:
    sf::FloatRect rect;
    sf::FloatRect box;

public:
    Monsters(float x, float y, sf::Texture& texture);
    virtual ~Monsters();

    const sf::Vector2f &getPosition() const;
    sf::FloatRect GlobalBounds();
    sf::FloatRect getHitbox();

    void anime(const float& x, const float& y);
    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);
};

#endif // MONSTERS_H
