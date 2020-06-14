#include "hitbox.h"

Hitbox::Hitbox(sf::Sprite& sprite, float x, float y, float width, float height)
    : sprite(sprite), pos_x(x), pos_y(y)
{
    hitbox.setPosition(this->sprite.getPosition().x + x, this->sprite.getPosition().y + y);
    hitbox.setSize(sf::Vector2f(width, height));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1.f);
    hitbox.setOutlineColor(sf::Color::Blue);
}

Hitbox::~Hitbox()
{

}

bool Hitbox::checkIntersect(const sf::FloatRect& rect)
{
    if(hitbox.getGlobalBounds().intersects(rect))
        return true;
    return false;
}

void Hitbox::update()
{
    hitbox.setPosition(this->sprite.getPosition().x + pos_x, this->sprite.getPosition().y + pos_y);
}

void Hitbox::render(sf::RenderTarget &target)
{
//    target.draw(hitbox);
}
