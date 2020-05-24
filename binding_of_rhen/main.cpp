#include <iostream>
#include <animation.h>
#include <player.h>
#include <monsters.h>

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1900,1000), "test");
    sf::Texture tex_hero;
    if(!tex_hero.loadFromFile("graphics/hero.png")) {return 1;}
    tex_hero.setSmooth(true);
    tex_hero.setRepeated(true);

    sf::Texture tex_stage;
    if(!tex_stage.loadFromFile("graphics/room.png")) {return 1;}
    sf::Sprite stage(tex_stage);

    player anime(&tex_hero, sf::Vector2u(30,6), 0.04f, 150.0f);

    std::vector<monsters> monsters_;
    sf::Texture gol_tex;
    if(!gol_tex.loadFromFile("graphics/golem1.png")) {return 1;}
    gol_tex.setSmooth(true);
    gol_tex.setRepeated(true);
    monsters_.emplace_back(monsters (&gol_tex, sf::Vector2u(24, 2), 0.06f, 150.0f));

    sf::Texture ogre_tex;
    if(!ogre_tex.loadFromFile("graphics/ogre1.png")) {return 1;}
    ogre_tex.setSmooth(true);
    ogre_tex.setRepeated(true);
    monsters_.emplace_back(monsters (&ogre_tex, sf::Vector2u(24, 2), 0.06f, 200.0f));

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
        anime.Draw(window);

        for(auto& el: monsters_){
            el.Update(deltaTime_);
            el.Draw(window);
        }

        window.display();
    }

    return 0;
}
