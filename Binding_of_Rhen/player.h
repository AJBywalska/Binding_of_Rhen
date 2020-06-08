#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    bool attacking;

    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    void updateAttack();
    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);

};

#endif // PLAYER_H
