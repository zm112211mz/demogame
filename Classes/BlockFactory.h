#pragma once

#include "GameBlock.h"
#include "DemoBlock.h"

enum blockType{
	demoBlockGap,
	demoBlock1,
	demoBlock2,
	demoBlock3,
	demoBlock4
};

class BlockFactory
{

	SpriteFrame * _tile1;
	SpriteFrame * _tile2;
	SpriteFrame * _tile3;
	SpriteFrame * _tile4;

	SpriteFrame * _roof1;
	SpriteFrame * _roof2;

	Sprite * _tileSample;
	Sprite * _roofSample;

	int _tileWidth;
	int _tileHeight;
	int _roofWidth;
	int _roofHeight;

	Array * _wallTiles;
	Array * _roofTiles;

	void init();
	DemoBlock *generateBlock(int width, int height, blockType type);
public:
	BlockFactory(void);
	~BlockFactory(void);

	static DemoBlock * getBlock(int width, int height, blockType type);
};

