//
//  Balk.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#include "Balk.h"

bool Balk::ms_isSpriteFramesInitialized = false;

Balk::Balk():m_type(BALK_NONE)
{
    if (!ms_isSpriteFramesInitialized)
    {
        ms_isSpriteFramesInitialized = initSpriteFrames();
    }
}

Balk::~Balk()
{
    
}

Balk* Balk::create()
{
    Balk *balk = new Balk();
    if (balk && balk->init())
    {
        balk->autorelease();
        return balk;
    }
    CC_SAFE_DELETE(balk);
    return nullptr;
}

Balk* Balk::createWithType(BalkType balkType)
{
    
    Balk *balk = new Balk();
    if (balk && balk->initWithType(balkType))
    {
        balk->autorelease();
        
        CCLOGINFO("Balk: create Balk with BalkType %d succeeded", balkType);
        
        return balk;
    }
    CC_SAFE_DELETE(balk);
    
    CCLOGERROR("Balk: create Balk with BalkType %d failed", balkType);
    
    return nullptr;
}

bool Balk::init()
{
    if (!cocos2d::Sprite::init())
    {
        return false;
    }
    return true;
}

bool Balk::initWithType(BalkType balkType)
{
    cocos2d::SpriteFrame *spriteFrame = ms_spriteFrames.at(balkType);
    
    if (cocos2d::Sprite::initWithSpriteFrame(spriteFrame))
    {
        CCLOGINFO("Balk: init Balk with BalkType %d succeeded", balkType);
        m_type = balkType;
        return true;
    }
    else
    {
        CCLOGERROR("Balk: init Balk with BalkType %d failed", balkType);
        return false;
    }
}

float Balk::getWidth()
{
    return cocos2d::Sprite::getContentSize().width;
}

float Balk::getHeight()
{
    return cocos2d::Sprite::getContentSize().height;
}

bool Balk::isPassAllowed(PlayerType playerType)
{
    bool allow = false;
    
    switch (playerType)
    {
        case PLAYER_CLOUD:
            switch (m_type)
            {
                case BALK_FIRE:
                case BALK_ROCK:
                case BALK_BIG_BALLNET:
                case BALK_BIG_GLASS:
                case BALK_BALLNET:
                case BALK_GLASS:
                case BALK_BIRD:
                case BALK_BAFFLE:
                    allow = false;
                    break;
                    
                default:
                    break;
            }
            break;
            
        case PLAYER_WATER:
            switch (m_type)
            {
                case BALK_BIG_BALLNET:
                case BALK_BALLNET:
                    allow = true;
                    break;
                    
                case BALK_FIRE:
                case BALK_ROCK:
                case BALK_BIG_GLASS:
                case BALK_GLASS:
                case BALK_BIRD:
                case BALK_BAFFLE:
                    allow = false;
                    break;
                    
                default:
                    break;
            }
            break;
            
        case PLAYER_ICE:
            switch (m_type)
            {
                case BALK_BIG_GLASS:
                case BALK_GLASS:
                    allow = true;
                    break;
                    
                case BALK_FIRE:
                case BALK_ROCK:
                case BALK_BIG_BALLNET:
                case BALK_BALLNET:
                case BALK_BIRD:
                case BALK_BAFFLE:
                    allow = false;
                    break;
                    
                default:
                    break;
            }
            break;
            
        default:
            break;
    }

    return allow;
}

void Balk::playPassAnimation(PlayerType playerType)
{
    
}

bool Balk::initSpriteFrames()
{
    cocos2d::SpriteFrame *spriteFrame = NULL;
    cocos2d::SpriteFrameCache *spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
    
    spriteFrame = spriteFrameCache->getSpriteFrameByName("balk_fire.png");
    ms_spriteFrames.insert(BALK_FIRE, spriteFrame);
    
    spriteFrame = spriteFrameCache->getSpriteFrameByName("balk_ballnet.png");
    ms_spriteFrames.insert(BALK_BALLNET, spriteFrame);
    
    return true;
}