#include "state.h"

State::State(sf::RenderWindow *window, std::stack<State*>* states)
{
    this->window_ = window;
    this->states = states;
    quit = false;
}

State::~State()
{

}

const bool &State::getQuit() const
{
    return quit;
}

void State::endState()
{
    quit = true;
}


void State::updateMousePos()
{
    mousePosView = window_->mapPixelToCoords(sf::Mouse::getPosition(*window_));
}
