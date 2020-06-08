#include "animation.h"


Animation::Animation(sf::Sprite &sprite, sf::Texture &textureSheet)
        : sprite(sprite), textureSheet(textureSheet), lastAnimation(NULL), priorityAnimation(NULL)
{

}

Animation::~Animation()
{
    for(auto &it : animations){
        delete it.second;
    }
}

const bool &Animation::isDone(const std::string key)
{
    return animations[key]->isDone();
}

void Animation::addAnimation(const std::string key, float speed, int startFrame_x, int startFrame_y,
    int frame_x, int frame_y, int width, int height)
{
    animations[key] = new Animation_(sprite, textureSheet, speed, startFrame_x,
              startFrame_y, frame_x, frame_y, width, height);
}

const bool& Animation::play(const std::string key, const float &deltaTime, const bool priority)
{
    if(priorityAnimation){

        if(priorityAnimation == animations[key]){

            if(lastAnimation != animations[key]){

                if(lastAnimation == nullptr)
                    lastAnimation = animations[key];

                else{
                    lastAnimation->reset();
                    lastAnimation = animations[key];
                }
            }
            if(animations[key]->play(deltaTime))
                priorityAnimation = nullptr;
         }
    }
    else{

        if(priority){
            priorityAnimation = animations[key];
        }

        if(lastAnimation != animations[key]){

            if(lastAnimation == nullptr)
                lastAnimation = animations[key];

            else{
                lastAnimation->reset();
                lastAnimation = animations[key];
            }
         }
        animations[key]->play(deltaTime);
       }
    return animations[key]->isDone();
}

const bool& Animation::play(const std::string key, const float &deltaTime, const float &modifier, const float &modifier_max, const bool priority)
{
    if(priorityAnimation){

        if(priorityAnimation == animations[key]){

            if(lastAnimation != animations[key]){

                if(lastAnimation == nullptr)
                    lastAnimation = animations[key];

                else{
                    lastAnimation->reset();
                    lastAnimation = animations[key];
                }
            }
            float value = abs(modifier/modifier_max);
            if(animations[key]->play(deltaTime, value))
                priorityAnimation = nullptr;
        }
    }
    else{

        if(priority){
            priorityAnimation = animations[key];
        }

        if(lastAnimation != animations[key]){

            if(lastAnimation == nullptr)
                lastAnimation = animations[key];

            else{
                lastAnimation->reset();
                lastAnimation = animations[key];
            }
        }
    float value = abs(modifier/modifier_max);
    animations[key] ->play(deltaTime, value);
    }
    return animations[key]->isDone();
}
