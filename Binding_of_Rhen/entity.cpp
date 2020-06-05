#include "entity.h"

Entity::Entity()
{
    texture = nullptr;
    sprite = nullptr;
    speed = 100.f;
}

Entity::~Entity()
{
    delete sprite;
}

void Entity::createSprite(sf::Texture *texture)
{
    this->texture = texture;
    this->sprite->setTexture(*texture);
}

void Entity::move(const float& deltaTime, const float x, const float y)
{
    if(sprite)
        sprite->move(x*speed*deltaTime,y*speed*deltaTime);
}

void Entity::update(const float &deltaTime)
{

}

void Entity::render(sf::RenderTarget* target)
{
    if(sprite)
        target->draw(*sprite);
}
