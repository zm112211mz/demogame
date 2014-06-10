//
//  Balk.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#include "Balk.h"

Balk::Balk():m_type(BALK_NONE)
{

}

Balk::~Balk()
{
    
}

bool Balk::init()
{
    if (!cocos2d::Sprite::init())
    {
        return false;
    }
    return true;
}

bool Balk::initWithType(BalkType type)
{
    if (!this->init())
    {
        return false;
    }
    m_type = type;
    
    // load image for different Balk type
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
            
        default:
            break;
    }
    return true;
}

bool Balk::allowPass(PlayerType playerType)
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