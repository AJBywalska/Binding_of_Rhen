#include "blank.h"

Blank::Blank(float x, float y, sf::Texture &texture)
{
    setPosition(x, y);
    createAnimation(texture);
    animation->addAnimation("idle", 4.f, 0, 0, 17, 0, 250, 250);
}

Blank::~Blank()
{

}
