/*
    �ļ�����    Terrain.h
    �衡����    ��Ϸ�ж���ĵ�����
    �����ˣ�    ������ (���ͣ�http://blog.csdn.net/haomengzhu)

    �������ڣ�   2013.12.05
*/
#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#define TILE_H_SIZE 6
#define TILE_W_SIZE 8

#include "cocos2d.h"
#include "GameBlock.h"
#include "Player.h"

USING_NS_CC;
using namespace std;

//������
class Terrain : public CCSprite {

	CCArray * _blockPool;
	int _blockPoolIndex;

	CCArray * _blocks;
	int _lastBlockHeight;
	int _lastBlockWidth;
	int _minTerrainWidth;

	bool _showGap;
	CCSize _screenSize;

	int _currentPatternIndex;
	int _currentPatternCnt;
	int _currentWidthIndex;
	int _currentHeightIndex;
	int _currentTypeIndex;

	int _increaseGapInterval;
	float _increaseGapTimer;
	int _gapSize;

	void initTerrain (void);
	void addBlocks(int currentWidth);

	void distributeBlocks();
	void initBlock(GameBlock * block);

	inline float getWidth () {

		int count = _blocks->count();
		int width = 0;
		GameBlock * block;
		for (int i = 0; i < count; i++) {
			block = (GameBlock *) _blocks->objectAtIndex(i);
			width += block->getWidth();
		}
		return width;
	}


public:

	Terrain(void);
	~Terrain(void);

	CC_SYNTHESIZE(bool, _startTerrain, StartTerrain);

	static Terrain * create();

	void activateChimneysAt (Player * player);
	void checkCollision (Player * player);

	void move (float xMove);
	void reset (void);


};


#endif // __TERRAIN_H__

