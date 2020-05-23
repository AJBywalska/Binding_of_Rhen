#include "animation.h"
#include "player.h"

animation::animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    rects.width = texture->getSize().x/float(imageCount.x);
    rects.height = texture->getSize().y/float(imageCount.y);
}

void animation::Update(int row, float deltaTime, bool faceRight)
{
    currentImage.y = row;
    totalTime += deltaTime;
    deltaTime_=deltaTime;

    if(totalTime >= switchTime){
        totalTime -= switchTime;
        currentImage.x++;

        if(currentImage.x >= imageCount.x){
            currentImage.x = 0;
        }
    }
    rects.top = currentImage.y*rects.height;

    if(faceRight){

        rects.left = currentImage.x*rects.width;
        rects.width = abs(rects.width);
    }
    else {
        rects.left = (currentImage.x+1)* abs(rects.width);
        rects.width = -abs(rects.width);
    }
}
