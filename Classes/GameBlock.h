#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

enum {
	kWallTile,
	kRoofTile,
	kChimney
};

enum {
	kBlockGap,
	kBlock1,
	kBlock2,
	kBlock3,
	kBlock4
};

class GameBlock : public GameSprite {
	CCSize _screenSize;

	int _tileWidth;
	int _tileHeight;
	int _puffIndex;
	float _scaleRate;

	SpriteFrame * _tile1;
	SpriteFrame * _tile2;
	SpriteFrame * _tile3;
	SpriteFrame * _tile4;

	SpriteFrame * _roof1;
	SpriteFrame * _roof2;

	Array * _wallTiles;
	Array * _roofTiles;

	Action * _puffSpawn;
	Action * _puffMove;
	Action * _puffFade;
	Action * _puffScale;
	Action * _puffAnimation;

	void initBlock(void);
	void createPuff(void);

public:
	CC_SYNTHESIZE(int, _type, Type);

	CC_SYNTHESIZE_READONLY(bool, _puffing, Puffing);

	CC_SYNTHESIZE(Array *, _chimneys, Chimneys);

	GameBlock(float scaleRate);
	~GameBlock();

	static GameBlock *create(float scaleRate);
	void setupBlock(int width, int height, int type, float scaleRate);
	void setPuffing(bool value);
	void hidePuffs();

	inline virtual int left() {
		return this->getPositionX();
	}

	inline virtual int right() {
		return this->getPositionX() + _width;
	}

	inline virtual int top() {
		return this->getHeight();
	}

	inline virtual int bottom() {
		return 0;
	}

};

#endif