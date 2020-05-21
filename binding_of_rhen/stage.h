#ifndef STAGE_H
#define STAGE_H
#include <memory>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class stage {
public:
    stage(int W, int H);
    void drawing();
    void loop();
    int getCoins();
    int getHearts();
    static int getWave() { which_wave++; return which_wave;}

protected:
    sf::RenderWindow window_;
    int W_;
    int H_;
    std::vector<sf::Sprite> stage_elements;
    std::vector<sf::Texture> textures_;
    int number_of_coins;
    int number_of_hearts;
    static int which_wave;
};

#endif // STAGE_H
