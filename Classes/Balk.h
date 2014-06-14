//
//  Balk.h
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#ifndef __MyGame__Balk__
#define __MyGame__Balk__

#include <iostream>
#include "cocos2d.h"
#include "GameTypes.h"


class Balk : public cocos2d::Sprite
{
public:
    Balk();
    ~Balk();
    
    static Balk* create();
    static Balk* createWithType(BalkType balkType);
    
    bool init();
    bool initWithType(BalkType balkType);
    
    float getWidth();
    float getHeight();
    
    // if the player can pass when player meets the Balk
    bool allowPass(PlayerType playerType);
    
    // play the animation when player passes the Balk
    void playPassAnimation(PlayerType playerType);
    
    CC_SYNTHESIZE_READONLY(BalkType, m_type, Type);
    
protected:
    
};

#endif /* defined(__MyGame__Balk__) */
