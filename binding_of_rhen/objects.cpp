#include "objects.h"
#include "stage.h"

objects::objects() : stage(1000, 1000)
{

}

void objects::move(sf::Sprite)
{

}

void objects::shoot()
{

}

void objects::getBonus()
{

}

sf::Vector2f objects::heroPosition() { return hero_.getPosition(); }
