#ifndef HITBOX_H
#define HITBOX_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Hitbox
{
private:
    sf::Sprite& sprite;
    sf::RectangleShape hitbox;
    float pos_x;
    float pos_y;

public:
    Hitbox(sf::Sprite& sprite, float x, float y, float width, float height);
    virtual ~Hitbox();

    bool checkIntersect(const sf::FloatRect& rect);

    void update();
    void render(sf::RenderTarget& target);
};

#endif // HITBOX_H
