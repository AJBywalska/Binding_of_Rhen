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

    temp.loadFromFile("graphics/tlo.png");
    textures["background"] = temp;
}

void GameState::initPlayers()
{
    player = new Player(780, 450, textures["idleFront"]);

    monsters.emplace_back(new Monsters(rand()%1700, rand()%800, textures["idleGolem"]));
    monsters.emplace_back(new Monsters(rand()%1700, rand()%800, textures["idleOgre"]));
    monsters.emplace_back(new Monsters(rand()%1700, rand()%800, textures["idleReape"]));

    map = new Map(0, 0 , textures["background"]);
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
    delete map;
}

bool GameState::intersect()
{
    for(auto &monster : monsters){
        if(player->GlobalBounds().top < monster->GlobalBounds().top + 20 && player->GlobalBounds().top + player->GlobalBounds().height > monster->GlobalBounds().top + 10 && player->GlobalBounds().left + player->GlobalBounds().width > monster->GlobalBounds().left + 20 && player->GlobalBounds().left < monster->GlobalBounds().left + monster->GlobalBounds().width - 10){
            player->setPosition(780, 450);
            return true;
        }
    }
    return false;
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

    if(player->GlobalBounds().left < 100)
        player->move(1.f, 0.f, deltaTime);
    if(player->GlobalBounds().left + player->GlobalBounds().width > 1820)
        player->move(-1.f, 0.f, deltaTime);
    if(player->GlobalBounds().top < -20)
        player->move(0.f, 1.f, deltaTime);
    if(player->GlobalBounds().top + player->GlobalBounds().height > 955)
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

        if(monster->GlobalBounds().left < 110)
            monster->move(1.f, 0.f, deltaTime);
        if(monster->GlobalBounds().left + monster->GlobalBounds().width > 1810)
            monster->move(-1.f, 0.f, deltaTime);
        if(monster->GlobalBounds().top < -10)
            monster->move(0.f, 1.f, deltaTime);
        if(monster->GlobalBounds().top + monster->GlobalBounds().height > 955)
            monster->move(0.f, -1.f, deltaTime);
    }

    if(intersect())
        player->loseHP();

    if(player->isDead())
    {
        font.loadFromFile("Fonts/Raleway-ExtraLightItalic.ttf");
        text.setPosition(700, 500);
        text.setFont(font);
        text.setCharacterSize(100);
        text.setOutlineColor(sf::Color::Red);
        text.setOutlineThickness(12);
        text.setString("Game Over!!!");
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

    map->update(deltaTime);
}

void GameState::render(sf::RenderTarget *target)
{
    if(!target)
        target = window_;
    map->render(*target);

    for(auto &it : monsters)
        it->render(*target);

    player->render(*target);


    sf::Text mouseText;
    sf::Font font;
    font.loadFromFile("Fonts/Raleway-ExtraLightItalic.ttf");
    mouseText.setPosition(this->mousePosView);
    mouseText.setFont(font);
    mouseText.setCharacterSize(20);
    std::stringstream ss;
    ss<<this->mousePosView.x<<" "<<this->mousePosView.y;
    mouseText.setString(ss.str());

    target->draw(mouseText);
    target->draw(text);
}
