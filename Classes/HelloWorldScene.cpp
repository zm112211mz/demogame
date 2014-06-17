#include "HelloWorldScene.h"
#include "BlockFactory.h"



Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	//init resource
    SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("sprite_sheet.plist","sprite_sheet.png");

	this->reset();
    
    return true;
}

void HelloWorld::reset()
{
	this->removeAllChildren();

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	//create menu
	_mainMenu = Menu::create();

	addMenuItem(_mainMenu, "Start Game", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	addMenuItem(_mainMenu, "Block Factory Test", CC_CALLBACK_1(HelloWorld::menuTestBlockFactory, this));
	addMenuItem(_mainMenu, "Start Game", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	addMenuItem(_mainMenu, "Exit", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	float Y_top, Y_end, Ydelta, Y;
	Y_top = Y = visibleSize.height * 0.8;
	Y_end = visibleSize.height * 0.2;
	Ydelta = (Y_top - Y_end)/(_mainMenu->getChildrenCount() + 1);

    for(const auto &child : _mainMenu->getChildren()) {
		Y -= Ydelta;
		child->setPosition( Point( visibleSize.width/2, Y) );
    }
	_mainMenu->setPosition(0,0);

	addChild(this->_mainMenu, 1);

	auto lable = CCLabelTTF::create("Back",  "Arial", 20);
    auto item = MenuItemLabel::create(lable, CC_CALLBACK_1(HelloWorld::menuCleanUp, this));
    item->setDisabledColor( Color3B(32,32,64) );
    item->setColor( Color3B(200,200,255) );
	item->setPosition(visibleSize.width - item->getContentSize().width, item->getContentSize().height);
	auto backMenu = Menu::create(item, NULL);
	backMenu->setPosition(0, 0);
	addChild(backMenu, 0);
}

//util function to add menuItem
void HelloWorld::addMenuItem(Menu *menu, std::string text, const ccMenuCallback& callback)
{
	auto lable = CCLabelTTF::create(text,  "Arial", 20);
    auto item = MenuItemLabel::create(lable, callback);
    item->setDisabledColor( Color3B(32,32,64) );
    item->setColor( Color3B(200,200,255) );

	this->_mainMenu->addChild(item);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuTestBlockFactory(Ref* pSender)
{
	this->_mainMenu->setVisible(false);
	DemoBlock *db = BlockFactory::getBlock(4, 4, demoBlockGap);
	db->setScale(3);
	this->addChild(db);
}

void HelloWorld::menuCleanUp(Ref* pSender)
{
	this->reset();
}

