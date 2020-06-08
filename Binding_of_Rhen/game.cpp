#include "game.h"

void Game::initWindow()
{
    this->window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "My Game", sf::Style::Fullscreen);
}

void Game::initStates()
{
    states.push(new MainMenu(window_, &states));
}

Game::Game()
{
    initWindow();
    initStates();
}

Game::~Game()
{
    delete window_;

    while (states.empty()) {
        delete states.top();
        states.pop();
    }
}

void Game::updateDt()
{
    deltaTime = clock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (window_->pollEvent(evnt))
    {
        if (evnt.type == sf::Event::Closed)
            window_->close();
    }
}

void Game::update()
{
    updateSFMLEvents();

    if(!states.empty()){
        states.top()->update(deltaTime);

        if(states.top()->getQuit()){
            states.top()->endState();
            delete states.top();
            states.pop();
        }
    }
    else{
        window_->close();
    }
}

void Game::render()
{
    window_->clear(sf::Color(207, 207, 207));

    if(!states.empty()){
        states.top()->render();
    }

    window_->display();
}

void Game::run()
{
    while (window_->isOpen())
    {
        updateDt();
        update();
        render();
    }
}

