#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    sf::FloatRect rect;
    bool attacking;

    sf::Font font;
    sf::Text hpBarText;
    std::string hpBarString;

    sf::Text scoreText;
    std::string scoreString;

    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarFront;
    float hpBarMaxWidth;
    float hpBarMaxHeight;

    sf::SoundBuffer music;
    sf::Sound sound;

    void initHPBar();

public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    const sf::Vector2f &getPosition() const;
    sf::FloatRect GlobalBounds();
    bool isAttacking();

    void updateText();
    void updateAttack();
    void updateAnimation(const float& deltaTime);
    virtual void update(const float& deltaTime);

    void renderText(sf::RenderTarget& target);
};

#endif // PLAYER_H
