#ifndef MAINMENU_H
#define MAINMENU_H

#include "gamestate.h"
#include "button.h"

class MainMenu : public State
{
private:
    sf::RectangleShape background;
    sf::Texture tex_back;
    sf::Sprite back;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    void initFonts();
    void initButtons();

public:
    MainMenu(sf::RenderWindow *window_, std::stack<State*>* states);
    virtual ~MainMenu();

    void updateKeyBinds(const float& deltaTime);
    void updateButtons();
    void update(const float& deltaTime);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // MAINMENU_H
