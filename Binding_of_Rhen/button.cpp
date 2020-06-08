#include "button.h"

Button::Button(float x, float y, float width, float height,
               sf::Font* font, std::string text, unsigned textSize,
               sf::Color text_idleColor, sf::Color text_hoverColor, sf::Color text_activeColor,
               sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    buttomState = idle;

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(idleColor);

    this->font = font;
    this->text.setFont(*font);
    this->text.setString(text);
    this->text.setFillColor(text_idleColor);
    this->text.setCharacterSize(textSize);
    this->text.setPosition(
          shape.getPosition().x + (shape.getGlobalBounds().width/2.f) - this->text.getGlobalBounds().width/2.f,
          shape.getPosition().y + (shape.getGlobalBounds().height/2.f) - this->text.getGlobalBounds().height/2.f);

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->text_idleColor = text_idleColor;
    this->text_hoverColor = text_hoverColor;
    this->text_activeColor = text_activeColor;
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
        text.setFillColor(text_idleColor);
        break;
    case hover:
        shape.setFillColor(hoverColor);
        text.setFillColor(text_hoverColor);
        break;
    case pressed:
        shape.setFillColor(activeColor);
        text.setFillColor(text_activeColor);
        break;
    default:
        shape.setFillColor(sf::Color::Red);
        text.setFillColor(sf::Color::Blue);
        break;
    }
}

void Button::render(sf::RenderTarget& target)
{
    target.draw(shape);
    target.draw(text);
}
