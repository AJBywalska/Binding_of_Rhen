#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

class GameState : public State
{
private:
    int random_direction;

    sf::Clock clock;
    sf::Time elapsed;
    float time = 0.f;
    const float timeLimit = 2.f;

    Player* player;
    std::vector<Monsters*> monsters;
    Movement* movment;

    void initTextures();
    void initPlayers();

public:
    GameState(sf::RenderWindow *window_, std::stack<State*>* states);
    virtual ~GameState();

    void updateKeyBinds(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
