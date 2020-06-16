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

    unsigned count = 0;
    bool getHeart;

    sf::Text text;
    sf::Text textwon;
    sf::Font font;

    sf::Clock timer;
    int timeToHeart = 0;
    float timeMax;

    Player* player;
    std::vector<Monsters*> monsters;
    Movement* movment;
    Map* map;
    Heart* heart;
    Blank* blank;
    std::vector<Fire*> fires;

    void initTextures();
    void initPlayers();
    void initTime();

public:
    GameState(sf::RenderWindow *window_, std::stack<State*>* states);
    virtual ~GameState();

    void removeMonster(const int index);

    bool intersectMonster();
    bool intersectHeart();
    bool intersectFire();
    bool getTime();

    void updateKeyBinds(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
