#ifndef ENTITY_H
#define ENTITY_H

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

class Entity
{
protected:
    sf::Texture* texture;
    sf::Sprite* sprite;
    float speed;

public:
    Entity();
    virtual ~Entity();

    void  createSprite(sf::Texture* texture);

    virtual void move(const float& deltaTime, const float x, const float y);

    virtual void update(const float& deltaTime);
    virtual void render(sf::RenderTarget* target);
};

#endif // ENTITY_H
