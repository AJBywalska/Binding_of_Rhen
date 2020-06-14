#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

class GameState : public State
{
private:
    int random1;
    int random2;
    int random3;
    int random_direction;

    int count = 0;

    sf::Text text;
    sf::Font font;

    sf::Clock timer;
    float timeMax;

    Player* player;
    std::vector<Monsters*> monsters;
    Movement* movment;
    Map* map;
    Heart* heart;
    Blank* blank;

    void initTextures();
    void initPlayers();
    void initTime();

public:
    GameState(sf::RenderWindow *window_, std::stack<State*>* states);
    virtual ~GameState();

    bool intersectMonster();
    bool intersectHeart();
    bool getTime();
    bool getHeartTime();

    void updateKeyBinds(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
