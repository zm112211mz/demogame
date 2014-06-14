#pragma once

#include "cocos2d.h"

USING_NS_CC;

class DemoBlock : public Sprite
{
	int _width;
	int _height;
	float _tileWidth;
	float _tileHeight;
	Vector<Sprite *> _tiles;
public:
	DemoBlock(int width, int height, float tileWidth, float tileHeight);
	~DemoBlock(void);
	bool addTile(int x, int y, Sprite * tile);
	bool addTiles(Vector<Sprite *> tilesArray);
	static DemoBlock *create(int width, int height, float tileWidth, float tileHeight);
	
	
};

