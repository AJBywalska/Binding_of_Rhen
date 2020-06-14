#include "gamestate.h"

void GameState::initTextures()
{
    sf::Texture temp;
    temp.loadFromFile("graphics/entire.png");
    textures["idleFront"] = temp;

    std::vector<sf::Texture> temp_tex(3);
    for(int i=0; i<3; i++)
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

    temp.loadFromFile("graphics/blank.png");
    textures["blank"] = temp;
}

void GameState::initPlayers()
{
    player = new Player(780, 450, textures["idleFront"]);

    monsters.emplace_back(new Monsters(150 + rand()%1500, 150 + rand()%800, textures["idleGolem"]));
    monsters.emplace_back(new Monsters(150 + rand()%1500, 150 + rand()%800, textures["idleOgre"]));
    monsters.emplace_back(new Monsters(150 + rand()%1500, 150 + rand()%800, textures["idleReape"]));

    blank = new Blank(-300, -300, textures["blank"]);
    map = new Map(0, 0 , textures["background"]);
}

void GameState::initTime()
{
    this->timeMax = 2.f;
    this->timer.restart();
}

GameState::GameState(sf::RenderWindow *window_, std::stack<State*>* states)
        : State(window_, states)
{
    initTextures();
    initPlayers();
    initTime();
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

bool GameState::getTime()
{
    if (this->timer.getElapsedTime().asSeconds() >= this->timeMax)
        {
            this->timer.restart();
            return true;
        }

        return false;
}



void GameState::updateKeyBinds(const float &deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        player->move(-3.f, 0.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        player->move(3.f, 0.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        player->move(0.f, -3.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        player->move(0.f, 3.f, deltaTime);}

    if(player->GlobalBounds().left < 100)
        player->move(3.f, 0.f, deltaTime);
    if(player->GlobalBounds().left + player->GlobalBounds().width > 1820)
        player->move(-3.f, 0.f, deltaTime);
    if(player->GlobalBounds().top < -20)
        player->move(0.f, 3.f, deltaTime);
    if(player->GlobalBounds().top + player->GlobalBounds().height > 955)
        player->move(0.f, -3.f, deltaTime);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        endState();

    for(auto &monster : monsters){

        if(monster->GlobalBounds().left < 110)
            monster->anime(1.f, 0.f);
        if(monster->GlobalBounds().left + monster->GlobalBounds().width > 1810)
            monster->anime(-1.f, 0.f);
        if(monster->GlobalBounds().top < -10)
            monster->anime(0.f, 1.f);
        if(monster->GlobalBounds().top + monster->GlobalBounds().height > 955)
            monster->anime(0.f, -1.f);
    }

    if(intersect())
        player->loseHP();


    if(player->isDead())
    {
        font.loadFromFile("Fonts/Raleway-ExtraLightItalic.ttf");
        text.setPosition(600, 450);
        text.setFont(font);
        text.setCharacterSize(100);
        text.setOutlineColor(sf::Color::Red);
        text.setOutlineThickness(12);
        text.setString("Game Over!!!");
    }

    for(int i=0; i<3; i++){
        if(monsters[i]->isDead()){
            count++;
            i++;}
    }

//    if(count == 3)
//    {
//        font.loadFromFile("Fonts/Raleway-ExtraLightItalic.ttf");
//        text.setPosition(600, 450);
//        text.setFont(font);
//        text.setCharacterSize(100);
//        text.setFillColor(sf::Color::Black);
//        text.setOutlineColor(sf::Color::White);
//        text.setOutlineThickness(12);
//        text.setString("YOU WON!!!");
//    }

    if(getTime()){
        random1 = rand()%4;
        random2 = rand()%4;
        random3 = rand()%4;
    }

    for(int i=0; i<3; i++){

        if(i == 0)
            random_direction = random1;
        if(i == 1)
            random_direction = random2;
        else
            random_direction = random3;

    switch (random_direction) {
        case 0: monsters[i]->anime(1.f, 0.f);
            break;
        case 1: monsters[i]->anime(-1.f, 0.f);
            break;
        case 2: monsters[i]->anime(0.f, 1.f);
            break;
        case 3: monsters[i]->anime(0.f, -1.f);
            break;
        }
    }

    if(player->isAttacking())
    for(auto &monster : monsters){
        if(player->hitbox->checkIntersect(monster->GlobalBounds())){
            monster->setPosition(150 + rand()%1500, 150 + rand()%800);
            monster->loseHP();
        }

    }


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

    for(auto &monster : monsters){
        if(monster->isDead())
            blank->render(*target);
        else
            monster->render(*target);
    }

    if(player->isDead())
        blank->render(*target);
    else
        player->render(*target);

    target->draw(text);
}
