//
//  TestBalkLayer.cpp
//  MyGame
//
//  Created by Yin Zhu on 6/15/14.
//
//

#include "Balk.h"
#include "TestBalkLayer.h"
#include "HelloWorldScene.h"

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
    
    cocos2d::Size screenSize = cocos2d::Director::getInstance()->getWinSize();
    
    cocos2d::Sprite *fire = Balk::createWithType(BALK_FIRE);
    fire->setPosition(50, 150);
    this->addChild(fire);
    
    cocos2d::Sprite *ballnet = Balk::createWithType(BALK_BALLNET);
    ballnet->setPosition(150, 150);
    this->addChild(ballnet);
    
    cocos2d::Label *label = cocos2d::Label::createWithSystemFont("Back",  "Arial", 20);
    cocos2d::MenuItemLabel *backMenuItem = cocos2d::MenuItemLabel::create(label, CC_CALLBACK_1(TestBalkLayer::backCallback, this));
    cocos2d::Menu *menu = cocos2d::Menu::create(backMenuItem, NULL);
    menu->setColor(cocos2d::Color3B::BLACK);
    menu->setPosition(screenSize.width - backMenuItem->getContentSize().width, backMenuItem->getContentSize().height);
    this->addChild(menu);
    
    return true;
}

void TestBalkLayer::backCallback(cocos2d::Ref *pSender)
{
    cocos2d::Director::getInstance()->replaceScene(HelloWorld::createScene());
}