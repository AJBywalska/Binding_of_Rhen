#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    sf::IntRect rect;
    bool attacking;

    sf::Font font;
    sf::Text text;

    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarFront;
    float hpBarMaxWidth;
    float hpBarMaxHeight;

    void initHPBar();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    const sf::Vector2f &getPosition() const;
    sf::IntRect GlobalBounds();
    bool isAttacking();

    void updateHPBar();
    void updateAttack();
    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);

    void renderHPBar(sf::RenderTarget& target);
};

#endif // PLAYER_H
