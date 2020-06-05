#include "button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font,
               std::string text, sf::Color idleColor,
               sf::Color hoverColor, sf::Color activeColor)
{
    buttomState = idle;

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(20);
    this->text.setPosition(
          this->shape.getPosition().x + (shape.getGlobalBounds().width/2.f) - this->text.getGlobalBounds().width/2.f,
          this->shape.getPosition().y + (shape.getGlobalBounds().height/2.f) - this->text.getGlobalBounds().height/2.f);

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    shape.setFillColor(idleColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
    if(buttomState == pressed)
        return true;

    return false;
}

void Button::update(const sf::Vector2f mousePos)
{
    buttomState = idle;

    if(shape.getGlobalBounds().contains(mousePos)){
        buttomState = hover;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            buttomState = pressed;
        }
    }

    switch (buttomState) {
    case idle:
        shape.setFillColor(idleColor);
        break;
    case hover:
        shape.setFillColor(hoverColor);
        break;
    case pressed:
        shape.setFillColor(activeColor);
        break;
    default:
        shape.setFillColor(sf::Color::Red);
        break;
    }
}

void Button::render(sf::RenderTarget *target)
{
    target->draw(shape);
    target->draw(text);
}
