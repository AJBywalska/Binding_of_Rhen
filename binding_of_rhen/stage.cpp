#include "stage.h"

stage::stage(int W, int H) : window_(sf::VideoMode(W, H), "Binding of Rhen")
{
    sf::Texture texture_room;
    if(!texture_room.loadFromFile("room.png")) { std::cout<<"ERROR!"; }
    textures_.emplace_back(texture_room);
    sf::Sprite room;
    room.setTexture(*(textures_.end()-1));
    stage_elements.emplace_back(room);

}

void stage::drawing()
{
   window_.clear(sf::Color::Black);
   for(auto& el: stage_elements)
       window_.draw(el);

   window_.display();
}

void stage::loop()
{
    while (window_.isOpen()) {
        sf::Event evnt;
        while (window_.pollEvent(evnt)) {
            if(evnt.type == sf::Event::Closed)
                window_.close();
        }
    }
}

int stage::getCoins() { return number_of_coins; }

int stage::getHearts() { return number_of_hearts; }

