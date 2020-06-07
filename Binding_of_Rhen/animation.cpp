#include "animation.h"


Animation::Animation(sf::Sprite &sprite, sf::Texture &textureSheet)
        : sprite(sprite), textureSheet(textureSheet)
{

}

Animation::~Animation()
{
    for(auto &it : animations){
        delete it.second;
    }
}

void Animation::addAnimation(const std::string key, float speed, int startFrame_x, int startFrame_y,
    int frame_x, int frame_y, int width, int height)
{
    animations[key] = new Animation_(sprite, textureSheet, speed, startFrame_x,
              startFrame_y, frame_x, frame_y, width, height);
}

void Animation::play(const std::string key, const float &deltaTime)
{
    animations[key]->play(deltaTime);
}
