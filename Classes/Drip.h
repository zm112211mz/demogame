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
#include "DemoSprite.h"

class Drip : public DemoSprite
{
public:
    ~Drip();
    
    static Drip* create(void);
    static Drip* createWithModality(DripModality dripModality);
    
    bool init(void);
    bool initWithModality(DripModality dripModality);
    
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
    
    // load the animate from file, called by initAnimates()
    //static cocos2d::Animate *loadAnimateByName(const std::string& frameName, int frameCount);
    
    // init all the Animates to accelerate the creating of Sprites, called in the first constructor of Drip
    static bool initAnimates(void);
    
    // if the Animates are initilized
    static bool ms_isAnimatesInitialized;
    
    // all the SpriteFrames
    //static cocos2d::Map<int, cocos2d::SpriteFrame *> ms_spriteFrames;
    
    // all the Animates
    static cocos2d::Map<int, cocos2d::Animate *> ms_animates;
};

#endif /* defined(__MyGame__Drip__) */
