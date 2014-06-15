//
//  Drip.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/14/14.
//
//

#include "Drip.h"

bool Drip::ms_isSpriteFramesInitialized = false;

Drip::Drip():m_modality(DRIP_MODALITY_WATER),m_nextModality(DRIP_MODALITY_WATER),m_state(DRIP_STATE_RUNNING)
{
    if (!ms_isSpriteFramesInitialized)
    {
        ms_isSpriteFramesInitialized = initSpriteFrames();
    }
}

Drip::~Drip()
{
    
}

Drip* Drip::create()
{
    Drip *drip = new Drip();
    if (drip && drip->init())
    {
        drip->autorelease();
        
        CCLOGINFO("Drip: create Drip succeeded");
        
        return drip;
    }
    CC_SAFE_DELETE(drip);
    
    CCLOGERROR("Drip: create Drip failed");
    
    return nullptr;
}

Drip* Drip::createWithModality(DripModality dripModality)
{
    Drip *drip = new Drip();
    if (drip && drip->initWithModality(dripModality))
    {
        drip->autorelease();
        
        CCLOGINFO("Drip: create Drip with DripModality %d succeeded", dripModality);
        
        return drip;
    }
    CC_SAFE_DELETE(drip);
    
    CCLOGERROR("Drip: create Drip with DripModality %d failed", dripModality);
    
    return nullptr;
}

bool Drip::init()
{
    // init the Drip with the default modality Water
    return initWithModality(DRIP_MODALITY_WATER);
}

bool Drip::initWithModality(DripModality dripModality)
{
    return true;
    /*
    cocos2d::SpriteFrame *spriteFrame = ms_spriteFrames.at(dripModality);
    
    if (cocos2d::Sprite::initWithSpriteFrame(spriteFrame))
    {
        CCLOGINFO("Drip: init Drip with DripModality %d succeeded", dripModality);
        m_modality = dripModality;
        m_nextModality = dripModality;
        return true;
    }
    else
    {
        CCLOGERROR("Drip: init Drip with DripModality %d failed", dripModality);
        return false;
    }*/
}

float Drip::getWidth()
{
    return cocos2d::Sprite::getContentSize().width;
}

float Drip::getHeight()
{
    return cocos2d::Sprite::getContentSize().height;
}

bool Drip::changeModality(DripModality dripModality)
{
    // Drip can change modality only when it is running
    if (m_state != DRIP_STATE_RUNNING)
    {
        CCLOGINFO("Drip: change DripModality to %d failed since the DripState is %d", dripModality, m_state);
        return false;
    }
    
    m_nextModality = dripModality;
    
    m_state = DRIP_STATE_MODALITYING;
    
    //cocos2d::Animation *animation = generateModalityingAnimation(m_modality, m_nextModality);
    
    //cocos2d::Action *action = cocos2d::Sequence::create(animation, NULL);
    
    //this->runAction(animation);

    return true;
}

bool Drip::update()
{
    return true;
}

bool Drip::isChangingModality()
{
    return (m_modality != m_nextModality);
}
/*
DripState Drip::calculateState(DripModality dripModality, DripModality nextDripModality)
{
    DripState state;
    if (dripModality == nextDripModality)
    {
        state = DRIP_STATE_RUNNING;
    }
    else
    {
        if (dripModality == DRIP_MODALITY_WATER)
        {
            if (nextDripModality == DRIP_MODALITY_CLOUD)
            {
                state = DRIP_STATE_WATER_TO_CLOUD;
            }
            else
            {
                state = DRIP_STATE_WATER_TO_ICE;
            }
        }
        else if (dripModality == DRIP_MODALITY_CLOUD)
        {
            if (nextDripModality == DRIP_MODALITY_WATER)
            {
                state = DRIP_STATE_CLOUD_TO_WATER;
            }
            else
            {
                state = DRIP_STATE_CLOUD_TO_ICE;
            }
        }
        else
        {
            if (nextDripModality == DRIP_MODALITY_CLOUD)
            {
                state = DRIP_STATE_ICE_TO_CLOUD;
            }
            else
            {
                state = DRIP_STATE_ICE_TO_WATER;
            }
        }
    }
    return state;
}*/


bool Drip::initSpriteFrames()
{
    return true;
}