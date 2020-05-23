#ifndef PLAYER_H
#define PLAYER_H
#include "animation.h"

class player
{
public:
    player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~player() {};
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

protected:
    sf::Sprite hero;
    animation anime;
    unsigned int row;
    float speed;
    bool faceRight;
    enum Direction {Up, Down, Right, Left};
};

#endif // PLAYER_H
