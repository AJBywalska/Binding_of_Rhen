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
    sf::Vector2i source(0, 1);
    sf::Vector2f movement(0.0f, 0.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        source.x = 1;
        source.y = Up;
        movement.y -= speed*deltaTime;
        speed=90;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        source.x = 1;
        source.y = Down;
        movement.y += speed*deltaTime;
        speed=90;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        source.x = 1;
        source.y = Left;
        movement.x -= speed*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        source.x = 1;
        source.y = Right;
        movement.x += speed*deltaTime;
    }

    if(source.y==Down){
        if(movement.y == 0)
            row=0;
        else
            row=1;
    }
    if(source.y==Right)
        row=3;
    if(source.y==Left)
        row=4;
    if(source.y==Up)
        row=5;

    anime.Update(row, deltaTime, faceRight);
    hero.setTextureRect(anime.rects);
    hero.move(movement);
}

void player::Draw(sf::RenderWindow& window)
{
    window.draw(hero);
}
