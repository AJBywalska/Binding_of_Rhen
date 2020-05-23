#include <iostream>
#include <animation.h>
#include <player.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1900,1000), "test");
    sf::Texture tex_hero;
    if(!tex_hero.loadFromFile("graphics/anime.png")) {return 1;}
    tex_hero.setSmooth(true);
    tex_hero.setRepeated(true);

    sf::Texture tex_stage;
    if(!tex_stage.loadFromFile("graphics/room.png")) {return 1;}
    sf::Sprite stage(tex_stage);

    player anime(&tex_hero, sf::Vector2u(30,6), 0.04f, 150.0f);

    float deltaTime_ = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime_=clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if(evnt.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(150, 150, 150));
        window.draw(stage);
        anime.Update(deltaTime_);
        //hero.setTextureRect(anime.rects);
        //window.draw(hero);
        anime.Draw(window);
        window.display();
    }

    return 0;
}
