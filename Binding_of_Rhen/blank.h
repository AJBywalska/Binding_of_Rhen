#ifndef BLANK_H
#define BLANK_H

#include "entity.h"

class Blank : public Entity
{
public:
    Blank(float x, float y, sf::Texture& texture);
    virtual ~Blank();
};

#endif // BLANK_H
