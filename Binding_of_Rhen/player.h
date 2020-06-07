#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    virtual void update(const float& deltaTime);

};

#endif // PLAYER_H
