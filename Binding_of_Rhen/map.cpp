#include "map.h"

Map::Map(float x, float y, sf::Texture &texture)
{
    setPosition(x, y);
    createAnimation(texture);

    animation->addAnimation("map", 1.f, 0, 0, 0, 0, 1920, 1080);
}

Map::~Map()
{

}

sf::IntRect Map::setGlobalBounds()
{
    rect.top = sprite.getGlobalBounds().top + 130;
    rect.left = sprite.getGlobalBounds().left + 100;
    rect.width = sprite.getGlobalBounds().width - 1660;
    rect.height = sprite.getGlobalBounds().height - 860;

    return rect;
}

void Map::updateAnimation(const float &deltaTime)
{
    animation->play("map", deltaTime);
}

void Map::update(const float &deltaTime)
{
    updateAnimation(deltaTime);
}
