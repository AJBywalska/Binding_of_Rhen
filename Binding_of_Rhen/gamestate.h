#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include <cmath>

class GameState : public State
{
private:
    int random1;
    int random2;
    int random3;
    int random4;
    int random5;
    int random6;
    int random7;
    int random8;
    int random9;
    int random10;
    int random11;
    int random12;

    int random_direction;
    int direction;

    unsigned count = 0;
    bool getHeart;

    sf::Text text;
    sf::Text textwon;
    sf::Font font;

    sf::Clock timer;
    int timeToHeart = 0;
    int timeToChange = 0;
    int timeToShoot = 0;
    float timeMax;

    Player* player;
    std::vector<Monsters*> monsters;
    Boss* boss;
    Movement* movment;
    Map* map;
    Heart* heart;
    Blank* blank;
    std::vector<Fire*> fires;
    std::vector<Shoot*> bullets;
    std::vector<BossShoot*> bossBullets;

    sf::SoundBuffer hurtMusic;
    sf::Sound hurtSound;

    void initTextures();
    void initPlayers();
    void initTime();

public:
    GameState(sf::RenderWindow *window_, std::stack<State*>* states);
    virtual ~GameState();

    void removeMonster(const int index);
    void removeShoot(const int index);
    void removeBossShoot(const int index);
    bool allMonstersAreDead();

    bool intersectMonster();
    bool intersectBoss();
    bool intersectHeart();
    bool intersectFire();
    bool getTime();

    bool toShoot(int i);

    void updateGame(const float& deltaTime);
    void update(const float& deltaTime);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // GAMESTATE_H
