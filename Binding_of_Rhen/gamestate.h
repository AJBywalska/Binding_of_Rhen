#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

class GameState : public State
{
private:
    Entity player;

public:
    GameState(sf::RenderWindow *window_, std::stack<State*>* states);
    virtual ~GameState();
    void updateKeyBinds(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
