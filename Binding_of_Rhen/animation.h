#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <string>
#include <map>
#include <cmath>

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
        bool done;
        int width;
        int height;
        sf::IntRect startRect;
        sf::IntRect currentRect;
        sf::IntRect endRect;

        Animation_(sf::Sprite& sprite, sf::Texture& textureSheet, float speed,
            int startFrame_x, int startFrame_y, int frame_x, int frame_y, int width, int height)
            : sprite(sprite), textureSheet(textureSheet), speed(speed),
              timer(0.f), done(false), width(width), height(height)
        {
            startRect = sf::IntRect(startFrame_x * width, startFrame_y * height, width, height);
            currentRect = startRect;
            endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);

            sprite.setTexture(textureSheet, true);
            sprite.setTextureRect(startRect);
        }

        const bool& isDone() const
        {
            return done;
        }

        const bool& play(const float& deltaTime){
            done = false;
            timer += 100.f * deltaTime;
            if(timer >= speed){

                if(currentRect != endRect){
                    currentRect.left += width;
                }
                else{
                    currentRect.left = startRect.left;
                    done = true;
                }
                sprite.setTextureRect(currentRect);
            }
            return done;
        }

        const bool& play(const float& deltaTime, float value){
            if(value < 0.5f)
                value = 0.5f;

            done = false;
            timer += value * 100.f * deltaTime;
            if(timer >= speed){
                timer = 0.f;

                if(currentRect != endRect){
                    currentRect.left += width;
                }
                else{
                    currentRect.left = startRect.left;
                    done = true;
                }
                sprite.setTextureRect(currentRect);
            }
            return done;
        }

        void reset(){
            timer = speed;
            currentRect = startRect;
        }
    };


    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string, Animation_*> animations;
    Animation_* lastAnimation;
    Animation_* priorityAnimation;

public:
    Animation(sf::Sprite& sprite, sf::Texture& textureSheet);
    virtual ~Animation();

    const bool &isDone(const std::string key);

    void addAnimation(const std::string key, float speed, int startFrame_x,
         int startFrame_y, int frame_x, int frame_y, int width, int height);

    const bool& play(const std::string key, const float& deltaTime, const bool priority = false);
    const bool& play(const std::string key, const float& deltaTime, const float& modifier, const float& modifier_max, const bool priority = false);
};

#endif // ANIMATION_H
