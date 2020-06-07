#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

enum Direction {didle = 0, moving, left, right, up, down};

class Movement
{
private:
    sf::Sprite& sprite;

    float maxVelocity;
    sf::Vector2f velocity;
    float acceleration_;
    float deceleration_;


public:
    Movement(sf::Sprite& sprite, float maxVelocity,
             float acceleration, float deceleration);
    virtual ~Movement();

    const sf::Vector2f &getVelocity() const;

    const bool getDirection(const short unsigned state) const;

    void move(const float x,const float y, const float& deltaTime);
    void update(const float& deltaTime);
};

#endif // MOVEMENT_H
