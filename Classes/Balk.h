//
//  Balk.h
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#ifndef __MyGame__Balk__
#define __MyGame__Balk__

#include "cocos2d.h"
#include "GameTypes.h"
#include "GameMacros.h"


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
    bool isPassAllowed(DripModality dripModality);
    
    // play the animation when player passes the Balk
    void playPassAnimation(DripModality dripModality);
    
    CC_SYNTHESIZE_READONLY(BalkType, m_type, Type);
    
protected:
    Balk();
    
    // init all the Animates to accelerate the creating of Sprites,
    // called in the first constructor of Balk
    static bool initAnimates(void);
    
    // if the Animates are initilized
    static bool ms_isAnimatesInitialized;
    
    // the SpriteFrames used to initilize the Sprites
    //static cocos2d::Map<int, cocos2d::SpriteFrame *> ms_spriteFrames;
    
    // all the animates
    static cocos2d::Map<int, cocos2d::Animate *> ms_animates;
    
    // pass animates
    static cocos2d::Map<int, cocos2d::Animate *> ms_passAnimates;
    
};

#endif /* defined(__MyGame__Balk__) */
