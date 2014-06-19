//
//  DemoSprite.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/18/14.
//
//

#include "DemoSprite.h"

DemoSprite::DemoSprite()
{
    
}

DemoSprite::~DemoSprite()
{
    
}

float DemoSprite::getWidth()
{
    return this->getContentSize().width;
}

float DemoSprite::getHeight()
{
    return this->getContentSize().height;
}

cocos2d::Animate* DemoSprite::loadAnimateByName(const std::string& frameName, int frameCount)
{
    cocos2d::SpriteFrameCache *spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
    
    cocos2d::SpriteFrame *spriteFrame = nullptr;
    cocos2d::AnimationFrame *animationFrame = nullptr;
    cocos2d::ValueMap userInfo;
    cocos2d::Vector<cocos2d::AnimationFrame *> animationFrames;
    cocos2d::Animation *animation = nullptr;
    char spriteName[255] = { 0 };
    
    for (int i = 1; i <= frameCount; ++ i)
    {
        sprintf(spriteName, "%s_%02d.png", frameName.c_str(), i);
        spriteFrame = cocos2d::SpriteFrame::create(spriteName, cocos2d::Rect(0, 0, 100, 100));
        animationFrame = cocos2d::AnimationFrame::create(spriteFrame, 1, userInfo);
        animationFrames.pushBack(animationFrame);
    }
    animation = cocos2d::Animation::create(animationFrames, ANIMATION_TIME_INTERVAL, ANIMATION_ENDLESS_LOOP);
    return cocos2d::Animate::create(animation);
}