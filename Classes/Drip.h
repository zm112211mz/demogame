//
//  Drip.h
//  MyGame
//
//  Created by Yin Zhu on 6/14/14.
//
//

#ifndef __MyGame__Drip__
#define __MyGame__Drip__

#include "cocos2d.h"
#include "GameTypes.h"
#include "GameMacros.h"

class Drip : public cocos2d::Sprite
{
public:
    ~Drip();
    
    static Drip* create(void);
    static Drip* createWithModality(DripModality dripModality);
    
    bool init(void);
    bool initWithModality(DripModality dripModality);
    
    float getWidth(void);
    float getHeight(void);
    
    // change from one DripModality to another
    bool changeModality(DripModality dripModality);

    // adjust the position according to Drip's state
    // adjust the animation according to Drip's state
    bool update(void);
    
    bool playPassAnimation(BalkType balkType);

    CC_SYNTHESIZE(float, m_speed, Speed);
    CC_SYNTHESIZE_READONLY(DripModality, m_modality, Modality);
    CC_SYNTHESIZE_READONLY(DripModality, m_nextModality, NextModality);
    CC_SYNTHESIZE_READONLY(DripState, m_state, State);
    
protected:
    Drip();
    
    // if the Drip is changing DripModality currently
    bool isChangingModality();
    
    // calculate the DripState according to current DripModality and next DripModality
    //DripState calculateState(DripModality dripModality, DripModality nextDripModality);
    
    cocos2d::Animation* generateModalityingAnimation(DripModality dripModality, DripModality nextDripModality);
    
    // init all the SpriteFrames to accelerate the creating of Sprites,
    // called in the first constructor of Drip
    static bool initSpriteFrames(void);
    
    // if the SpriteFrames are initilized
    static bool ms_isSpriteFramesInitialized;
    
    // all the SpriteFrames
    static cocos2d::Map<int, cocos2d::SpriteFrame *> ms_spriteFrames;
    
    // all the AnimationFrames
    static cocos2d::Map<int, cocos2d::Animation *> ms_animations;
};

#endif /* defined(__MyGame__Drip__) */
