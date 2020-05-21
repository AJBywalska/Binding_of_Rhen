#ifndef OBJECTS_H
#define OBJECTS_H
#include "stage.h"

class objects : public stage
{
public:
    objects();
    void move(sf::Sprite);
    void shoot();
    void getBonus();
    sf::Vector2f heroPosition();
    bool is_touched();
    void loses_heart();
    void bounce();

protected:
    sf::Sprite hero_;
    std::vector<sf::Sprite> monsters_;
    std::vector<sf::Sprite> bonuses_;
    std::vector<sf::Sprite> shots_;

};

#endif // OBJECTS_H
