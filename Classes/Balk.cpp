//
//  Balk.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#include "Balk.h"

bool Balk::ms_isSpriteFramesInitialized = false;

cocos2d::Map<int, cocos2d::SpriteFrame *> Balk::ms_spriteFrames;

cocos2d::Map<int, cocos2d::Animate *> Balk::ms_animates;

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
        
        CCLOGINFO("Balk: create Balk succeeded");
        
        return balk;
    }
    CC_SAFE_DELETE(balk);
    
    CCLOGERROR("Balk: create Balk failed");
    
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
    if (cocos2d::Sprite::init())
    {
        CCLOGINFO("Balk: init Balk succeeded");
        return true;
    }
    else
    {
        CCLOGERROR("Balk: init Balk failed");
        return false;
    }
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

bool Balk::isPassAllowed(DripModality dripModality)
{
    bool allow = false;
    
    switch (dripModality)
    {
        case DRIP_MODALITY_CLOUD:
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
            
        case DRIP_MODALITY_WATER:
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
            
        case DRIP_MODALITY_ICE:
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

void Balk::playPassAnimation(DripModality dripModality)
{
    
}

bool Balk::initSpriteFrames()
{
    cocos2d::SpriteFrame *spriteFrame = nullptr;
    //cocos2d::SpriteFrameCache *spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();

    //spriteFrame = spriteFrameCache->getSpriteFrameByName("balk_fire.png");
    spriteFrame = cocos2d::SpriteFrame::create("balk_fire.png", cocos2d::Rect(0, 0, 100, 100));
    //spriteFrameCache->addSpriteFrame(spriteFrame, "balk_fire");
    ms_spriteFrames.insert(BALK_FIRE, spriteFrame);
    
    spriteFrame = cocos2d::SpriteFrame::create("balk_ballnet.png", cocos2d::Rect(0, 0, 100, 100));
    //spriteFrameCache->addSpriteFrame(spriteFrame, "balk_ballnet");
    //spriteFrame = spriteFrameCache->getSpriteFrameByName("balk_ballnet.png");
    ms_spriteFrames.insert(BALK_BALLNET, spriteFrame);
    
    return true;
}