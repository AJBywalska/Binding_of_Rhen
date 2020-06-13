#ifndef GAME_H
#define GAME_H

#include "mainmenu.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
    sf::RenderWindow *window_;
    sf::Event evnt;

    std::vector<sf::VideoMode> videModes;
    sf::ContextSettings windowSettings;
    bool fullscrean;

    sf::Clock clock;
    float deltaTime;

    std::stack<State*> states;

    void initWindow();
    void initStates();

public:
    Game();
    virtual ~Game();

    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};

#endif // GAME_H
