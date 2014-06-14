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
    ~Balk();
    
    static Balk* create(void);
    static Balk* createWithType(BalkType balkType);
    
    bool init(void);
    bool initWithType(BalkType balkType);
    
    float getWidth(void);
    float getHeight(void);
    
    // if the player can pass when player meets the Balk
    bool isPassAllowed(PlayerType playerType);
    
    // play the animation when player passes the Balk
    void playPassAnimation(PlayerType playerType);
    
    CC_SYNTHESIZE_READONLY(BalkType, m_type, Type);
    
protected:
    Balk();
    
    // init all the SpriteFrames to accelerate the creating of Sprites,
    // called in the first constructor of Balk
    static bool initSpriteFrames(void);
    
    // if the SpriteFrames are initilized
    static bool ms_isSpriteFramesInitialized;
    
    // all the SpriteFrames
    static cocos2d::Map<BalkType, cocos2d::SpriteFrame *> ms_spriteFrames;
    
};

#endif /* defined(__MyGame__Balk__) */
