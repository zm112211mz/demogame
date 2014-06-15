//
//  TestBalkLayer.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/15/14.
//
//

#include "Balk.h"
#include "TestBalkLayer.h"

TestBalkLayer::TestBalkLayer()
{

}

TestBalkLayer::~TestBalkLayer()
{
    
}

bool TestBalkLayer::init()
{
    if (!LayerColor::initWithColor(cocos2d::Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    
    cocos2d::Sprite *fire = Balk::createWithType(BALK_FIRE);
    fire->setPosition(50, 150);
    this->addChild(fire);
    
    cocos2d::Sprite *ballnet = Balk::createWithType(BALK_BALLNET);
    ballnet->setPosition(150, 150);
    this->addChild(ballnet);
    
    return true;
}