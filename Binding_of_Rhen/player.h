#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    sf::IntRect rect;
    bool attacking;

    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    const sf::Vector2f &getPosition() const;
    sf::IntRect setGlobalBounds();

    void updateAttack();
    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);

};

#endif // PLAYER_H
