#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#define TILE_H_SIZE 6
#define TILE_W_SIZE 8

#include "cocos2d.h"
#include "GameBlock.h"
#include "Player.h"
#include "GameTypes.h"
#include "Balk.h"

USING_NS_CC;
using namespace std;

class Terrain : public Sprite {

	__Array *_blockPool;
	int _blockPoolIndex;

	__Array *_blocks;
	int _lastBlockHeight;
	int _lastBlockWidth;
	int _minTerrainWidth;

	__Array *_balkPool;
	int _balkPoolIndex;

	__Array *_balks;
	int _lastBalkHeight;
	int _lastBalkWidth;

	bool _showGap;
    Size _screenSize;

	int _currentPatternIndex;
	int _currentPatternCnt;
	int _currentWidthIndex;
	int _currentHeightIndex;
	int _currentTypeIndex;
	int _currentBalkTypeIndex;

	int _increaseGapInterval;
	float _increaseGapTimer;
	int _gapSize;

	float _scaleRate;

	void initTerrain(void);
	void addBlocks(int currentWidth);
	void addBalks(int currentWidth);

	void distributeBlocks();
	void distributeBalks();

	void initBlock(GameBlock * block);
	void initBalk(Balk * balk);
	inline float getWidth() {
		int count = _blocks->count();
		int width = 0;
		GameBlock * block;
		for (int i = 0; i < count; i++) {
			block = (GameBlock *) _blocks->getObjectAtIndex(i);
			width += block->getWidth();
		}
		return width;
	}

public:
	Terrain(void);
	~Terrain(void);

	CC_SYNTHESIZE(bool, _startTerrain, StartTerrain);

	static Terrain * create(float scaleRate);

	void activateChimneysAt(Player * player);
	void checkCollision(Player * player);

	void move(float xMove);
	void reset(void);
	void setScaleRate(float scaleRate)
	{
		this->_scaleRate = scaleRate;
	}
	float getScaleRate()
	{
		return _scaleRate;
	}
};


#endif // __TERRAIN_H__

