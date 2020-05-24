#ifndef MONSTERS_H
#define MONSTERS_H
#include "animation.h"

class monsters
{
public:
    monsters(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

protected:
    sf::Sprite monster;
    std::vector<sf::Sprite> monsters_;
    animation anime;
    unsigned int row;
    float speed;
    bool faceRight;
    enum Direction {Up, Down, Right, Left};
};

#endif // MONSTERS_H
