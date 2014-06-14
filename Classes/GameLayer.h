/*
    文件名：    GameLayer.h
    描　述：    游戏中定义的游戏界面
    创建人：    郝萌主 (博客：http://blog.csdn.net/haomengzhu)

    创建日期：   2013.12.05
*/
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"
#include "Terrain.h"
#include "Player.h"

USING_NS_CC;

typedef enum {
	kGameIntro,//游戏介绍
	kGamePlay,//开始游戏
    kGameOver,//游戏结束
    kGameTutorial,//
    kGameTutorialJump,//
    kGameTutorialFloat,//
    kGameTutorialDrop//

} GameState;

class GameLayer : public cocos2d::CCLayer
{
	Terrain * _terrain;
	Player * _player;
	CCLabelBMFont * _scoreDisplay;

	Sprite * _intro;
	Sprite * _tryAgain;
	Sprite * _background;
	Sprite * _foreground;
	Sprite * _hat;
	Sprite * _jam;
	Action * _jamAnimate;
	Action * _jamMove;

	Array * _clouds;
	SpriteBatchNode * _gameBatchNode;
    CCLabelTTF * _tutorialLabel;
    CCMenu* _mainMenu;

	Size _screenSize;

    GameState _state;
	bool _running;
    float _score;
	int _speedIncreaseInterval;
	float _speedIncreaseTimer;
	float _scaleRate;
	void createGameScreen();
	void resetGame();
	void checkScaleRate(Size screenSize, Size bgSize);

public:
    ~GameLayer();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::Scene* scene();

    // implement the "static node()" method manually
    CREATE_FUNC(GameLayer);

	void update (float dt);

	virtual void onTouchesBegan(CCSet *pTouches, CCEvent *event);
	virtual void onTouchesEnded(CCSet *pTouches, CCEvent *event);

	virtual bool onTouchBegan(Touch *touch, Event *unused_event); 
    virtual void onTouchEnded(Touch *touch, Event *unused_event); 

    void showTutorial (CCObject* pSender);
    void startGame (CCObject* pSender);
};

#endif  // __HELLOWORLD_SCENE_H__