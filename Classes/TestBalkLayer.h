//
//  TestBalkLayer.h
//  MyGame
//
//  Created by Yin Zhu on 6/15/14.
//
//

#ifndef __MyGame__TestBalkScene__
#define __MyGame__TestBalkScene__

#include "cocos2d.h"
#include "GameMacros.h"

class TestBalkLayer : public cocos2d::LayerColor
{
public:
    virtual ~TestBalkLayer();
    
    virtual bool init();
    
    CREATE_FUNC(TestBalkLayer);
    SCENE_FUNC(TestBalkLayer);

protected:
    TestBalkLayer();
    
    void backCallback(cocos2d::Ref *pSender);
};

#endif /* defined(__MyGame__TestBalkScene__) */
