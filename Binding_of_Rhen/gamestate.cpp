#include "gamestate.h"

void GameState::initTextures()
{
    sf::Texture temp;
    temp.loadFromFile("graphics/heroall.png");
    textures["idleFront"] = temp;
}

void GameState::initPlayers()
{
    player = new Player(0, 0, textures["idleFront"]);
}

GameState::GameState(sf::RenderWindow *window_, std::stack<State*>* states)
        : State(window_, states)
{
    initTextures();
    initPlayers();
}

GameState::~GameState()
{
    delete player;
}

void GameState::updateKeyBinds(const float &deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player->move(deltaTime, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player->move(deltaTime, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player->move(deltaTime, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player->move(deltaTime, 0.f, 1.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        endState();
}

void GameState::update(const float &deltaTime)
{
    updateMousePos();
    updateKeyBinds(deltaTime);

    player->update(deltaTime);
}

void GameState::render(sf::RenderTarget *target)
{
    if(!target)
        target = window_;

    player->render(*target);
}
