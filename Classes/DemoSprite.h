//
//  DemoSprite.h
//  MyGame
//
//  Created by Yin Zhu on 6/18/14.
//
//

#ifndef __MyGame__DemoSprite__
#define __MyGame__DemoSprite__

#include "cocos2d.h"
#include "GameMacros.h"

class DemoSprite : public cocos2d::Sprite
{
public:
    virtual ~DemoSprite();
    
    virtual float getWidth(void);
    virtual float getHeight(void);
    
protected:
    DemoSprite();
    
    // load the animate from file, called by initAnimates()
    static cocos2d::Animate* loadAnimateByName(const std::string& frameName, int frameCount);
};
#endif /* defined(__MyGame__DemoSprite__) */
