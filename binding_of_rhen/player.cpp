#include "player.h"

player::player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
    : anime(texture,imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight=true;

    hero.setPosition(200, 200);
    hero.setScale(0.4, 0.4);
    hero.setTexture(*texture);
}

void player::Update(float deltaTime)
{
     int source = Down;
    sf::Vector2f movement(0.0f, 0.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        source = Up;
        movement.y -= speed*deltaTime;
        speed=90;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        source = Down;
        movement.y += speed*deltaTime;
        speed=90;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        source = Left;
        movement.x -= speed*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        source = Right;
        movement.x += speed*deltaTime;
    }

    if(source == Down){
        if(movement.y == 0)
            row=0;
        else
            row=1;
    }
    if(source == Right)
        row=3;
    if(source == Left)
        row=4;
    if(source == Up)
        row=5;

    anime.Update(row, deltaTime, faceRight);
    hero.setTextureRect(anime.rects);
    hero.move(movement);
}

void player::Draw(sf::RenderWindow& window)
{
    window.draw(hero);
}
