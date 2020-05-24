#include "monsters.h"

monsters::monsters(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed)
            : anime(texture,imageCount, switchTime)
{
    this->speed = speed;
    row = 1;
    faceRight=true;

    monster.setScale(0.4, 0.4);
    monster.setPosition(rand()%1800, rand()%800);
    monster.setTexture(*texture);
    //monsters_.emplace_back(monster);
}

void monsters::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x +=speed*deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -=speed*deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y +=speed*deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -=speed*deltaTime;

    if(movement.x == 0.0f && movement.y==0.0f){
        row=0;
        if(anime.rects.left>=8100)
            anime.rects.left=0;
    }
    else{
        row=1;
        if(movement.x>0.0f || movement.y<0.0f)
            faceRight=true;
        else
            faceRight=false;
    }

    anime.Update(row, deltaTime, faceRight);
    monster.setTextureRect(anime.rects);
    monster.move(movement);
}

void monsters::Draw(sf::RenderWindow &window)
{

        window.draw(monster);

}
