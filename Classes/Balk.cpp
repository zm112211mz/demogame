//
//  Balk.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#include "Balk.h"

bool Balk::ms_isAnimatesInitialized = false;

//cocos2d::Map<int, cocos2d::SpriteFrame *> Balk::ms_spriteFrames;

cocos2d::Map<int, cocos2d::Animate *> Balk::ms_animates;
cocos2d::Map<int, cocos2d::Animate *> Balk::ms_passAnimates;

Balk::Balk():m_type(BALK_NONE)
{
    if (!ms_isAnimatesInitialized)
    {
        ms_isAnimatesInitialized = initAnimates();
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
    //cocos2d::SpriteFrame *spriteFrame = ms_spriteFrames.at(balkType);
    
    //if (cocos2d::Sprite::initWithSpriteFrame(spriteFrame))
    if (cocos2d::Sprite::init())
    {
        m_type = balkType;
        this->runAction(ms_animates.at(balkType)->clone());
        
        CCLOGINFO("Balk: init Balk with BalkType %d succeeded", balkType);
        return true;
    }
    else
    {
        CCLOGERROR("Balk: init Balk with BalkType %d failed", balkType);
        return false;
    }
    
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
    this->runAction(ms_passAnimates.at(m_type));
}

bool Balk::initAnimates()
{
    /*
    cocos2d::SpriteFrame *spriteFrame = nullptr;
    cocos2d::AnimationFrame *animationFrame = nullptr;
    cocos2d::ValueMap userInfo;
    cocos2d::Vector<cocos2d::AnimationFrame *> animationFrames;
    
    //cocos2d::SpriteFrameCache *spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();

    spriteFrame = cocos2d::SpriteFrame::create("balk_fire.png", cocos2d::Rect(0, 0, 100, 100));
    //ms_spriteFrames.insert(BALK_FIRE, spriteFrame);
    animationFrame = cocos2d::AnimationFrame::create(spriteFrame, 1, userInfo);
    animationFrames.pushBack(animationFrame);
    //animation->addSpriteFrame(spriteFrame);
    
    spriteFrame = cocos2d::SpriteFrame::create("balk_ballnet.png", cocos2d::Rect(0, 0, 100, 100));
    //ms_spriteFrames.insert(BALK_BALLNET, spriteFrame);
    animationFrame = cocos2d::AnimationFrame::create(spriteFrame, 1, userInfo);
    animationFrames.pushBack(animationFrame);
    //animation->addSpriteFrame(spriteFrame);

    cocos2d::Animation *animation = cocos2d::Animation::create(animationFrames, 0.5f, ANIMATION_ENDLESS_LOOP);
    
    ms_animates.insert(BALK_FIRE, cocos2d::Animate::create(animation));
    ms_animates.insert(BALK_ROCK, cocos2d::Animate::create(animation));
    ms_animates.insert(BALK_BIG_BALLNET, cocos2d::Animate::create(animation));
    ms_animates.insert(BALK_BIG_GLASS, cocos2d::Animate::create(animation));
    ms_animates.insert(BALK_BALLNET, cocos2d::Animate::create(animation));
    ms_animates.insert(BALK_GLASS, cocos2d::Animate::create(animation));
    ms_animates.insert(BALK_BIRD, cocos2d::Animate::create(animation));
    ms_animates.insert(BALK_BAFFLE, cocos2d::Animate::create(animation));
     */
    ms_animates.insert(BALK_FIRE, loadAnimateByName("balk_fire", 2));
    ms_animates.insert(BALK_BALLNET, loadAnimateByName("balk_fire", 2));
    
    return true;
}