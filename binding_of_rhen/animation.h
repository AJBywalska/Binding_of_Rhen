#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <memory>
#include <cmath>
#include <fstream>
#include <sstream>
#include <ctime>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class animation
{
public:
    animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~animation() {};
    void Update(int row, float deltaTime, bool faceRight);
    sf::IntRect rects;

protected:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float deltaTime_;
    float totalTime;
    float switchTime;
};

#endif // ANIMATION_H
