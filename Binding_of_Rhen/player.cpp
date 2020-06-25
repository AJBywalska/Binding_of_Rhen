#include "player.h"

void Player::initHPBar()
{
    hpBarMaxWidth  = 300.f;

    hpBarBack.setSize(sf::Vector2f(300.f, 50.f));
    hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
    hpBarBack.setPosition(100.f, 20.f);

    hpBarFront.setSize(sf::Vector2f(300.f, 50.f));
    hpBarFront.setFillColor(sf::Color(250, 20, 20, 200));
    hpBarFront.setPosition(hpBarBack.getPosition());

    hpBarText.setFont(font);
    hpBarText.setCharacterSize(25);
    hpBarText.setFillColor(sf::Color::White);
    hpBarText.setPosition(120, 25);
    hpBarText.setOutlineThickness(1);

    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(900, 30);
    scoreText.setOutlineThickness(2);
}

Player::Player(float x, float y, sf::Texture& texture)
{
    setPosition(x, y);
    GlobalBounds();

    hp = hpMax/2;

    points = 0;

    attacking = false;

    createMovment(300.f);
    createAnimation(texture);
    createHitbox(sprite, 40.f, 95.f, 200.f, 200.f);

    initHPBar();

    animation->addAnimation("idleFront", 3.f, 0, 0, 29, 0, 300, 300);
    animation->addAnimation("walkDown", 6.f, 0, 1, 29, 1, 300, 300);
    animation->addAnimation("walkRight", 6.f, 0, 2, 29, 2, 300, 300);
    animation->addAnimation("walkLeft", 6.f, 0, 3, 29, 3, 300, 300);
    animation->addAnimation("walkUp", 6.f, 0, 4, 29, 4, 300, 300);
    animation->addAnimation("attackDown", 1.f, 0, 5, 14, 5, 300, 300);
    animation->addAnimation("attackRight", 3.f, 0, 6, 14, 6, 300, 300);
    animation->addAnimation("attackLeft", 3.f, 0, 7, 14, 7, 300, 300);
    animation->addAnimation("attackUp", 1.f, 0, 8, 14, 8, 300, 300);
    animation->addAnimation("dead", 3.f, 0, 0, 29, 0, 300, 300);

    font.loadFromFile("Fonts/Raleway-ExtraLightItalic.ttf");

    music.loadFromFile("sounds/sword.wav");
}

Player::~Player()
{

}

const sf::Vector2f &Player::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect Player::GlobalBounds()
{
    rect.top = sprite.getGlobalBounds().top + 60;
    rect.left = sprite.getGlobalBounds().left + 85;
    rect.width = sprite.getGlobalBounds().width - 170;
    rect.height = sprite.getGlobalBounds().height - 125;

    return rect;
}

bool Player::isAttacking()
{
    if(attacking)
        return true;
    return false;
}

void Player::updateText()
{
    float percent = static_cast<float>(std::floor(hp))/static_cast<float>(std::floor(hpMax));

    hpBarFront.setSize(sf::Vector2f(static_cast<float>(std::floor(hpBarMaxWidth * percent)), hpBarFront.getSize().y));

    hpBarString = std::to_string(hp) + " / " + std::to_string(hpMax);
    hpBarText.setString(hpBarString);

    scoreString = "Score: " + std::to_string(points);
    scoreText.setString(scoreString);
}

void Player::updateAttack()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        attacking = true;
        sound.setBuffer(music);
        sound.play();
    }
}

void Player::updateAnimation(const float &deltaTime)
{
    if(attacking){
        if(movment->getDirection(down))
            if(animation->play("attackDown", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
        if(movment->getDirection(up))
            if(animation->play("attackUp", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
        if(movment->getDirection(left))
            if(animation->play("attackLeft", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
        if(movment->getDirection(right))
            if(animation->play("attackRight", deltaTime, movment->getVelocity().x, movment->getMaxVelocity()/*, true*/))
                attacking = false;
    }

    else if(movment->getVelocity().x == 0.f && movment->getVelocity().y == 0.f)
        animation->play("idleFront", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    else if(movment->getDirection(left))
        animation->play("walkLeft", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    else if(movment->getDirection(right))
        animation->play("walkRight", deltaTime, movment->getVelocity().x, movment->getMaxVelocity());
    else if(movment->getDirection(up))
        animation->play("walkUp", deltaTime, movment->getVelocity().y, movment->getMaxVelocity());
    else if(movment->getDirection(down))
        animation->play("walkDown", deltaTime, movment->getVelocity().y, movment->getMaxVelocity());
}

void Player::update(const float &deltaTime)
{
    updateAttack();
    updateAnimation(deltaTime);

    updateText();

    hitbox->update();
}

void Player::renderText(sf::RenderTarget &target)
{
    target.draw(hpBarBack);
    target.draw(hpBarFront);
    target.draw(hpBarText);

    target.draw(scoreText);
}
