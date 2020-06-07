#include "mainmenu.h"

void MainMenu::initFonts()
{
    if(!font.loadFromFile("Fonts/Raleway-ExtraLightItalic.ttf")) {std::cout<<"FONT ERROR";}
}

void MainMenu::initButtons()
{
    buttons["gameButton"] = new Button(200.f, 200.f, 300.f, 60.f, &font, "New Game", 50,
       sf::Color(31, 31, 31, 200), sf::Color(217, 217, 217, 250), sf::Color(20, 20, 20, 50),
       sf::Color(70, 70, 70, 0), sf::Color(115, 115, 115, 0), sf::Color(20, 20, 20, 0));

    buttons["exitButton"] = new Button(200.f, 500.f, 300.f, 60.f, &font, "Exit Game", 50,
       sf::Color(31, 31, 31, 200), sf::Color(217, 217, 217, 250), sf::Color(20, 20, 20, 50),
       sf::Color(70, 70, 70, 0), sf::Color(115, 115, 115, 0), sf::Color(20, 20, 20, 0));
}

MainMenu::MainMenu(sf::RenderWindow *window_, std::stack<State*>* states)
        : State(window_, states)
{
    initFonts();
    initButtons();

    if(!tex_back.loadFromFile("graphics/menu.png")) { std::cout<<"TEXTURE ERROR\n";}
    back.setTexture(tex_back);
}

MainMenu::~MainMenu()
{
    for(auto it = buttons.begin(); it != buttons.end(); it++){
        delete it->second;
    }
}

void MainMenu::updateKeyBinds(const float &deltaTime)
{

}

void MainMenu::updateButtons()
{
    for(auto &it : buttons){
        it.second->update(mousePosView);
    }

    if(buttons["gameButton"]->isPressed()){
        states->push(new GameState(window_, states));
    }

    if(buttons["exitButton"]->isPressed()){
        endState();
    }
}

void MainMenu::update(const float &deltaTime)
{
    updateMousePos();
    updateKeyBinds(deltaTime);

    updateButtons();
}

void MainMenu::renderButtons(sf::RenderTarget *target)
{
    for(auto &it : buttons){
        it.second->render(target);
    }
}

void MainMenu::render(sf::RenderTarget *target)
{
    if(!target)
        target = window_;

    target->draw(back);

    renderButtons(target);
}
