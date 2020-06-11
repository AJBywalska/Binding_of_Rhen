#include "gamestate.h"

void GameState::initTextures()
{
    sf::Texture temp;
    temp.loadFromFile("graphics/entire.png");
    textures["idleFront"] = temp;

    std::vector<sf::Texture> temp_tex(4);
    for(int i=0; i<4; i++)
    {
        temp_tex[0].loadFromFile("graphics/golem.png");
        textures["idleGolem"] = temp_tex[0];
        temp_tex[1].loadFromFile("graphics/ogre.png");
        textures["idleOgre"] = temp_tex[1];
        temp_tex[2].loadFromFile("graphics/reaper.png");
        textures["idleReape"] = temp_tex[2];
    }
}

void GameState::initPlayers()
{
    player = new Player(0, 0, textures["idleFront"]);
    monsters.emplace_back(new Monsters(rand()%1900, rand()%900, textures["idleGolem"]));
    monsters.emplace_back(new Monsters(rand()%1900, rand()%900, textures["idleOgre"]));
    monsters.emplace_back(new Monsters(rand()%1900, rand()%900, textures["idleReape"]));
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
    for(auto &it : monsters)
        delete it;
}



void GameState::updateKeyBinds(const float &deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        player->move(-1.f, 0.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        player->move(1.f, 0.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        player->move(0.f, -1.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        player->move(0.f, 1.f, deltaTime);}

    if(player->setGlobalBounds().left < 0)
        player->move(1.f, 0.f, deltaTime);
    if(player->setGlobalBounds().left + player->setGlobalBounds().width > 1920)
        player->move(-1.f, 0.f, deltaTime);
    if(player->setGlobalBounds().top < 0)
        player->move(0.f, 1.f, deltaTime);
    if(player->setGlobalBounds().top + player->setGlobalBounds().height > 1080)
        player->move(0.f, -1.f, deltaTime);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        endState();

for(auto &monster : monsters){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    monster->move(-1.f, 0.f, deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    monster->move(1.f, 0.f, deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    monster->move(0.f, -1.f, deltaTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
     monster->move(0.f, 1.f, deltaTime);

    if(monster->setGlobalBounds().left < 0)
        monster->move(1.f, 0.f, deltaTime);
    if(monster->setGlobalBounds().left + monster->setGlobalBounds().width > 1920)
        monster->move(-1.f, 0.f, deltaTime);
    if(monster->setGlobalBounds().top < 0)
        monster->move(0.f, 1.f, deltaTime);
    if(monster->setGlobalBounds().top + monster->setGlobalBounds().height > 1080)
        monster->move(0.f, -1.f, deltaTime);
}

//    time += elapsed.asSeconds();

//    if(time >= timeLimit){
//         time -= timeLimit;
//        for(auto &monster : monsters){
//        random_direction = rand()%4;
//            switch (random_direction) {
//            case 0: speed_x = 1; speed_y = 0;
//                monster->move(-std::abs(speed_x), speed_y, deltaTime);
//                break;
//            case 1: speed_x = 1; speed_y = 0;
//                monster->move(speed_x, speed_y, deltaTime);
//                break;
//            case 2: speed_x = 0; speed_y = 1;
//                monster->move(speed_x, speed_y, deltaTime);
//                break;
//            case 3: speed_x = 0; speed_y = 1;
//                monster->move(speed_x, -std::abs(speed_y), deltaTime);
//                break;
//            }
//        }
//    }

}

void GameState::update(const float &deltaTime)
{
    updateMousePos();
    updateKeyBinds(deltaTime);

    player->update(deltaTime);

    for(auto &it : monsters)
        it->update(deltaTime);
}

void GameState::render(sf::RenderTarget *target)
{
    if(!target)
        target = window_;

    for(auto &it : monsters)
        it->render(*target);

    player->render(*target); 
}
