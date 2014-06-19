#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
	Menu *_mainMenu;

	void addMenuItem(Menu *menu, std::string text, const ccMenuCallback& callback);
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuStartGameCallback(cocos2d::Ref* pSender);

	void menuTestBlockFactoryCallback(cocos2d::Ref* pSender);
    
    void menuTestBalkCallback(cocos2d::Ref* pSender);

	void menuCloseCallback(cocos2d::Ref* pSender);

	void menuCleanUp(Ref* pSender);

	void reset();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
