#ifndef STATE_H
#define STATE_H

#include "entity.h"

class State
{
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window_;
    std::vector<sf::Texture> textures;
    bool quit;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;
    virtual void endState();

    virtual void updateMousePos();
    virtual void updateKeyBinds(const float& deltaTime) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif // STATE_H
