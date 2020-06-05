#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum buttom_states{idle = 0, hover, pressed};

class Button
{
private:
    short unsigned buttomState;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height, sf::Font* font,
           std::string text, sf::Color idleColor,
           sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    const bool isPressed() const;

    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);
};

#endif // BUTTON_H
