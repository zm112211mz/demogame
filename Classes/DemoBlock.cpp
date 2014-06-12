#include "DemoBlock.h"


DemoBlock::DemoBlock(int width, int height, float tileWidth, float tileHeight)
{
	_width = width <= 0 ? 1: width;
	_height = height <= 0 ? 1:height;
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
	Size contentSize;
	contentSize.width = width * tileWidth;
	contentSize.height = height * tileHeight;
	this->setContentSize(contentSize);
	//_tiles = Array::createWithCapacity(width * height);

	this->setAnchorPoint(ccp(0,0));
	this->setPosition(0,0);
}


DemoBlock::~DemoBlock(void)
{
}

bool DemoBlock::addTile(int x, int y, Sprite * tile)
{
	//_tiles->addObject(tile);
	Size contentSize;
	contentSize.width = _tileWidth;
	contentSize.height = _tileHeight;
	tile->setContentSize(contentSize);
	tile->setPosition(x * _tileWidth, y * _tileHeight);
	tile->setAnchorPoint(ccp(0, 0));
	this->addChild(tile);
	return true;
}
