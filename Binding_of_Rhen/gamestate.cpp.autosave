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

    temp.loadFromFile("graphics/boss.png");
    textures["boss"] = temp;

    temp.loadFromFile("graphics/tlo.png");
    textures["background"] = temp;

    temp.loadFromFile("graphics/blank.png");
    textures["blank"] = temp;

    temp.loadFromFile("graphics/heart.png");
    textures["heart"] = temp;

    temp.loadFromFile("graphics/fire.png");
    textures["fire"] = temp;

    temp.loadFromFile("graphics/shoot.png");
    textures["shoot"] = temp;

    temp.loadFromFile("graphics/bossShoot.png");
    textures["bossShoot"] = temp;
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

    boss = new Boss(1000, 1000, textures["boss"]);

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
    delete boss;
    delete map;
    delete blank;
    delete heart;
    for(auto &it : fires)
        delete it;
    for(auto &it : bullets)
        delete it;
    for(auto &it : bossBullets)
        delete it;
}

void GameState::removeMonster(const int index)
{
    delete monsters[index];
    monsters.erase(monsters.begin() + index);
}

void GameState::removeShoot(const int index)
{
    delete bullets[index];
    bullets.erase(bullets.begin() + index);
}

void GameState::removeBossShoot(const int index)
{
    delete bossBullets[index];
    bossBullets.erase(bossBullets.begin() + index);
}

bool GameState::allMonstersAreDead()
{
    if(count == 12)
        return true;
    else
        return false;
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

bool GameState::intersectBoss()
{
    if(boss->hitbox->checkIntersect(player->GlobalBounds())){
        player->setPosition(30, -20);
        return true;
    }
    else
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
    if (this->timer.getElapsedTime().asSeconds() >= this->timeMax){
            this->timer.restart();
            return true;
        }
    return false;
}

void GameState::updateGame(const float &deltaTime)
{

    for(unsigned i=0; i<bullets.size(); i++){
        if(bullets[i]->hitbox->checkIntersect(player->GlobalBounds())){
            removeShoot(i);
            player->loseHP();
            player->losePoints(5);
        }
    }

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

    if(player->isDead() || player->points < 0)
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

        text.setPosition(550, 450);
        text.setFont(font);
        text.setCharacterSize(70);
        text.setFillColor(sf::Color::Black);
        text.setOutlineColor(sf::Color::Red);
        text.setOutlineThickness(12);
        text.setString("You have been burned...");
    }

//WIN

    if(allMonstersAreDead()){
        boss->setPosition(500, 0);
    }

    if(boss->isDead()){
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

//CHANGE DIRECTION

        random1 = rand()%4;
        random2 = rand()%4;

        if(timeToChange > 1){
            random3 = rand()%4;
            random4 = rand()%4;
        }

        if(timeToChange > 2){
            random5 = rand()%4;
            random6 = rand()%4;
        }

        if(timeToChange > 3){
            random7 = rand()%4;
            random8 = rand()%4;
        }

        if(timeToChange > 4){
            random9 = rand()%4;
            random10 = rand()%4;
        }

        if(timeToChange > 5){
            random11 = rand()%4;
            random12 = rand()%4;
            timeToChange = 0;
        }

//HEART

        if(timeToHeart > 10){
            timeToHeart = 0;
            heart->setPosition(150 + rand()%1500, 150 + rand()%600);
            getHeart = false;
        }

//SHOOT

        if(timeToShoot > 2){
            timeToShoot = 0;

            for(unsigned i=8; i<12; i++){
                bullets.emplace_back(new Shoot(monsters[i]->getPosition().x+50, monsters[i]->getPosition().y+100, textures["shoot"]));

            for(unsigned j=0; j<bullets.size(); j++) {
                    if(bullets[j]->getPosition().x < monsters[i]->getPosition().x-400 || bullets[j]->getPosition().x > monsters[i]->getPosition().x+550 || bullets[j]->getPosition().y < monsters[i]->getPosition().y-400 || bullets[j]->getPosition().y > monsters[i]->getPosition().y+550){
                        delete bullets[j];
                        bullets.erase(bullets.begin() + j);
                    }
                }
            }
        }

        if(timeToShoot > 1){

        if(allMonstersAreDead()){

            if(player->GlobalBounds().top > 700.f && player->GlobalBounds().left > 700.f && player->GlobalBounds().left < 1300){
                direction = 0;
                bossBullets.emplace_back(new BossShoot(850, 500, textures["bossShoot"]));
            }

            else if(player->GlobalBounds().top < 200.f && player->GlobalBounds().left > 700.f && player->GlobalBounds().left < 1300){
                direction = 1;
                bossBullets.emplace_back(new BossShoot(750, 500, textures["bossShoot"]));
            }

            else if(player->GlobalBounds().left < 600.f && player->GlobalBounds().top > 100.f && player->GlobalBounds().top < 800){
                direction = 2;
                bossBullets.emplace_back(new BossShoot(750, 300, textures["bossShoot"]));
                bossBullets.emplace_back(new BossShoot(750, 500, textures["bossShoot"]));
            }

            else if(player->GlobalBounds().left > 600.f && player->GlobalBounds().top > 100.f && player->GlobalBounds().top < 800){
                direction = 3;
                bossBullets.emplace_back(new BossShoot(750, 300, textures["bossShoot"]));
                bossBullets.emplace_back(new BossShoot(750, 500, textures["bossShoot"]));
            }

            for(unsigned j=0; j<bossBullets.size(); j++){
                if(bossBullets[j]->getPosition().x < 0 || bossBullets[j]->getPosition().x > 1800 || bossBullets[j]->getPosition().y < 0 || bossBullets[j]->getPosition().y > 900){
                    delete bossBullets[j];
                    bossBullets.erase(bossBullets.begin() + j);;
                }
            }
        }

        }

        timeToHeart++;
        timeToChange++;
        timeToShoot++;
    }

//MONSTER MOVING

    for(unsigned i=0; i<monsters.size(); i++){

        if(i == 0)
            random_direction = random1;
        if(i == 1)
            random_direction = random2;
        if(i == 2)
            random_direction = random3;
        if(i == 3)
            random_direction = random4;
        if(i == 4)
            random_direction = random5;
        if(i == 5)
            random_direction = random6;
        if(i == 6)
            random_direction = random7;
        if(i == 7)
            random_direction = random8;
        if(i == 8)
            random_direction = random9;
        if(i == 9)
            random_direction = random10;
        if(i == 10)
            random_direction = random11;
        if(i == 11)
            random_direction = random12;


        switch (random_direction) {
            case 0: monsters[i]->anime(0.5f, 0.f);
                break;
            case 1: monsters[i]->anime(-0.5f, 0.f);
                break;
            case 2: monsters[i]->anime(0.f, 0.5f);
                break;
            case 3: monsters[i]->anime(0.f, -0.5f);
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
    if(player->hitbox->checkIntersect(boss->GlobalBounds())){
        player->setPosition(30, -20);
        boss->loseHP();
        player->gainPoints(15);
    }
}

//UPDATE

void GameState::update(const float &deltaTime)
{
    updateMousePos();
    updateGame(deltaTime);

    player->update(deltaTime);

    for(auto &monster : monsters)
        monster->update(deltaTime);

    boss->update(deltaTime);

    map->update(deltaTime);

    heart->update(deltaTime);

    for(auto &fire : fires)
        fire->update(deltaTime);

    for(auto &bullet : bullets)
        bullet->update(deltaTime);

    for(unsigned j=0; j<bullets.size(); j++){
        switch (random_direction) {
        case 0: bullets[j]->shooting(0.f, -0.5f);
            break;
        case 1: bullets[j]->shooting(0.f, 0.5f);
            break;
        case 2: bullets[j]->shooting(-0.5f, 0.f);
            break;
        case 3: bullets[j]->shooting(0.5f, 0.f);
            break;
        }
    }

    for(auto &bullet : bossBullets)
        bullet->update(deltaTime);

    for(unsigned i=0; i<bossBullets.size(); i++){
        switch (direction) {
        case 0: bossBullets[i]->shooting(0.f, 1.f);
            break;
        case 1: bossBullets[i]->shooting(0.f, -1.f);
            break;
        case 2: bossBullets[i]->shooting(-1.f, 0.f);
            break;
        case 3: bossBullets[i]->shooting(1.f, 0.f);
            break;
        }
    }
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

    for(auto &it : bullets)
            it->render(*target);

        for(unsigned i=0; i<bossBullets.size(); i++){
            if(bossBullets[i]->hitbox->checkIntersect(player->GlobalBounds())){
                removeBossShoot(i);
                player->loseHP();
                player->losePoints(20);
            }
            else
                bossBullets[i]->render(*target);
        }

        for(unsigned i=0; i<monsters.size(); i++){
            if(monsters[i]->isDead()){
                removeMonster(i);
                count++;
            }
            else
                monsters[i]->render(*target);
        }

        if(boss->isDead()){
            boss->setPosition(1000, 1000);
            blank->render(*target);
        }
        else
            boss->render(*target);

    if(player->isDead())
        blank->render(*target);
    else
        player->render(*target);

    target->draw(text);
}
