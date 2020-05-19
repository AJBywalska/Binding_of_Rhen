#ifndef STAGE_H
#define STAGE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <cmath>
#include <fstream>
#include <sstream>

class stage : public sf::Drawable {
public:
    stage(int W, int H);
    void drawing();

protected:
    sf::RenderWindow window_;

};

#endif // STAGE_H
