#pragma once

#include "GameTypes.h"
#include "DemoBlock.h"


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

	Vector<Sprite *> _wallTiles;
	Vector<Sprite *> _roofTiles;

	void init();
	DemoBlock *generateBlock(int width, int height, BlockType type);
public:
	BlockFactory(void);
	~BlockFactory(void);

	static DemoBlock * getBlock(int width, int height, BlockType type);
};

