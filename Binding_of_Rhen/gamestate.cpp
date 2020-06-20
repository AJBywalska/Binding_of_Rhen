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

    temp.loadFromFile("graphics/heart.png");
    textures["heart"] = temp;

    temp.loadFromFile("graphics/fire.png");
    textures["fire"] = temp;
}

void GameState::initPlayers()
{
    player = new Player(30, -20, textures["idleFront"]);

    for(int i=0; i<12; i++){
        if(i<4)
            monsters.emplace_back(new Monsters(150 + rand()%1500, 150 + rand()%600, textures["idleGolem"]));
        if(i<8 && i>=4)
            monsters.emplace_back(new Monsters(150 + rand()%1500, 150 + rand()%600, textures["idleOgre"]));
        if(i>=8)
            monsters.emplace_back(new Monsters(150 + rand()%1500, 150 + rand()%600, textures["idleReape"]));
    }

    heart = new Heart(150 + rand()%1500, 150 + rand()%600, textures["heart"]);
    blank = new Blank(-3000, -3000, textures["blank"]);
    map = new Map(0, 0 , textures["background"]);

    fires.emplace_back(new Fire(250, 200, textures["fire"]));
    fires.emplace_back(new Fire(1450, 200, textures["fire"]));
    fires.emplace_back(new Fire(250, 600, textures["fire"]));
    fires.emplace_back(new Fire(1450, 600, textures["fire"]));
}

void GameState::initTime()
{
    this->timeMax = 0.5f;
    this->timer.restart();
}

GameState::GameState(sf::RenderWindow *window_, std::stack<State*>* states)
        : State(window_, states)
{
    font.loadFromFile("Fonts/Raleway-ExtraLightItalic.ttf");
    hurtMusic.loadFromFile("sounds/hurt.wav");

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
    delete blank;
    delete heart;
    for(auto &it : fires)
        delete it;
}

void GameState::removeMonster(const int index)
{
    delete monsters[index];
    monsters.erase(monsters.begin() + index);
}

bool GameState::intersectMonster()
{
    for(auto &monster : monsters){
        if(player->GlobalBounds().top < monster->GlobalBounds().top + 20 && player->GlobalBounds().top + player->GlobalBounds().height > monster->GlobalBounds().top + 10 && player->GlobalBounds().left + player->GlobalBounds().width > monster->GlobalBounds().left + 20 && player->GlobalBounds().left < monster->GlobalBounds().left + monster->GlobalBounds().width - 10){
            player->setPosition(30, -20);
            return true;
        }
    }
    return false;
}

bool GameState::intersectHeart()
{
    if(heart->hitbox->checkIntersect(player->GlobalBounds())){
        getHeart = true;
        return true;
    }
    else
        return false;
}

bool GameState::intersectFire()
{
    for(auto &fire : fires)
    if(fire->hitbox->checkIntersect(player->GlobalBounds())){
        return true;
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

//PLAYER MOVING

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        player->move(-2.f, 0.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player->move(2.f, 0.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        player->move(0.f, -2.f, deltaTime);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player->move(0.f, 2.f, deltaTime);}

    if(player->GlobalBounds().left < 100)
        player->move(2.f, 0.f, deltaTime);
    if(player->GlobalBounds().left + player->GlobalBounds().width > 1820)
        player->move(-2.f, 0.f, deltaTime);
    if(player->GlobalBounds().top < -20)
        player->move(0.f, 2.f, deltaTime);
    if(player->GlobalBounds().top + player->GlobalBounds().height > 955)
        player->move(0.f, -2.f, deltaTime);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        endState();

//MONSTER MOVING

    for(auto &monster : monsters){
        for(auto &fire : fires){

            if(monster->GlobalBounds().left < 110 || fire->hitbox->checkIntersect(monster->GlobalBounds()))
                monster->anime(0.5f, 0.f);
            if(monster->GlobalBounds().left + monster->GlobalBounds().width > 1810 || fire->hitbox->checkIntersect(monster->GlobalBounds()))
                monster->anime(-0.5f, 0.f);
            if(monster->GlobalBounds().top < -10 || fire->hitbox->checkIntersect(monster->GlobalBounds()))
                monster->anime(0.f, 0.5f);
            if(monster->GlobalBounds().top + monster->GlobalBounds().height > 955 || fire->hitbox->checkIntersect(monster->GlobalBounds()))
                monster->anime(0.f, -0.5f);
        }
    }

//HURT

    if(intersectMonster()){
        hurtSound.setBuffer(hurtMusic);
        hurtSound.play();
        player->loseHP();
        player->losePoints(10);
    }

    if(intersectHeart()){
        heart->setPosition(-100, -100);
        player->gainHP();
    }

//DEAD

    if(player->isDead())
    {
        text.setPosition(600, 450);
        text.setFont(font);
        text.setCharacterSize(100);
        text.setOutlineColor(sf::Color::Red);
        text.setOutlineThickness(12);
        text.setString("Game Over!!!");

        hurtSound.setBuffer(hurtMusic);
        hurtSound.play();
    }

    if(intersectFire()){
        player->loseHP();

        text.setPosition(650, 450);
        text.setFont(font);
        text.setCharacterSize(70);
        text.setFillColor(sf::Color::Black);
        text.setOutlineColor(sf::Color::Red);
        text.setOutlineThickness(12);
        text.setString("You have burned...");
    }

//WIN

    if(count == 12)
    {
        text.setPosition(650, 450);
        text.setFont(font);
        text.setCharacterSize(100);
        text.setFillColor(sf::Color::Black);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(12);
        text.setString("YOU WON!!!");
    }

//GET TIME

    if(getTime()){
        random1 = rand()%4;
        random2 = rand()%4;
        random3 = rand()%4;

        timeToHeart++;

        if(timeToHeart > 10){
            timeToHeart = 0;
            heart->setPosition(150 + rand()%1500, 150 + rand()%600);
            getHeart = false;
        }
    }

    for(unsigned i=0; i<monsters.size(); i++){

        if(i == 0)
            random_direction = random1;
        if(i == 1)
            random_direction = random2;
        else
            random_direction = random3;

    switch (random_direction) {
        case 0: monsters[i]->anime(0.5f, 0.f);
            break;
        case 1: monsters[i]->anime(-0.5f, 0.f);
            break;
        case 2: monsters[i]->anime(0.f, 0.5f);
            break;
        case 3: monsters[i]->anime(0.f, -0.5f);
            break;
        default: random_direction--;
            break;
        }
    }

//ATTACK

    if(player->isAttacking())
    for(auto &monster : monsters){
        if(player->hitbox->checkIntersect(monster->GlobalBounds())){
            monster->setPosition(150 + rand()%1500, 150 + rand()%600);
            monster->loseHP();
            player->gainPoints(5);
        }

    }
}

//UPDATE

void GameState::update(const float &deltaTime)
{
    updateMousePos();
    updateKeyBinds(deltaTime);

    player->update(deltaTime);

    for(auto &monster : monsters)
        monster->update(deltaTime);

    map->update(deltaTime);

    heart->update(deltaTime);

    for(auto &fire : fires)
        fire->update(deltaTime);
}

//RENDER

void GameState::render(sf::RenderTarget *target)
{
    if(!target)
        target = window_;

    map->render(*target);

    player->renderText(*target);

    for(auto &fire : fires)
        fire->render(*target);

    if(getHeart == true || timeToHeart > 4){
        heart->setPosition(-100, -100);
        blank->render(*target);
    }
    else
        heart->render(*target);

    for(auto &monster : monsters)
            monster->render(*target);

    for(unsigned i=0; i<monsters.size(); i++){
        if(monsters[i]->isDead()){
            removeMonster(i);
            count++;
        }
    }

    if(player->isDead())
        blank->render(*target);
    else
        player->render(*target);

    target->draw(text);
}
