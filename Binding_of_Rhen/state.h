#ifndef STATE_H
#define STATE_H

#include "player.h"
#include "monsters.h"
#include "boss.h"
#include "map.h"
#include "blank.h"
#include "heart.h"
#include "fire.h"
#include "shoot.h"
#include "bossshoot.h"

class State
{
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window_;
    std::map<std::string, sf::Texture> textures;
    bool quit;

    sf::Vector2f mousePosView;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;
    virtual void endState();

    virtual void updateMousePos();
    virtual void updateGame(const float& deltaTime) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif // STATE_H
