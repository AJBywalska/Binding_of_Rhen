#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Animation
{
private:
    class Animation_{
    public:
        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        float speed;
        float timer;
        int width;
        int height;
        sf::IntRect startRect;
        sf::IntRect currentRect;
        sf::IntRect endRect;

        Animation_(sf::Sprite& sprite, sf::Texture& textureSheet, float speed,
            int startFrame_x, int startFrame_y, int frame_x, int frame_y, int width, int height)
            : sprite(sprite), textureSheet(textureSheet), speed(speed), width(width), height(height)
        {
            timer = 0.f;
            startRect = sf::IntRect(startFrame_x * width, startFrame_y * height, width, height);
            currentRect = startRect;
            endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);

            sprite.setTexture(textureSheet, true);
            sprite.setTextureRect(startRect);
        }

        void play(const float& deltaTime){
            timer += 100.f * deltaTime;
            if(timer >= speed){
                timer = 0.f;

                if(currentRect != endRect){
                    currentRect.left += width;
                }
                else{
                    currentRect.left = startRect.left;
                }
                sprite.setTextureRect(currentRect);
            }
        }

        void reset(){
            timer = 0.f;
            currentRect = startRect;
        }
    };


    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string, Animation_*> animations;

public:
    Animation(sf::Sprite& sprite, sf::Texture& textureSheet);
    virtual ~Animation();

    void addAnimation(const std::string key, float speed, int startFrame_x,
         int startFrame_y, int frame_x, int frame_y, int width, int height);

    void play(const std::string key, const float& deltaTime);
};

#endif // ANIMATION_H
