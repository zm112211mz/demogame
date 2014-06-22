#include "DemoBlock.h"


DemoBlock::DemoBlock(int width, int height, float tileWidth, float tileHeight)
{
	_width = width <= 0 ? 1: width;
	_height = height <= 0 ? 1:height;
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
	_resistance = 0;
	Size contentSize;
	//contentSize.width = width * tileWidth;
	//contentSize.height = height * tileHeight;
	contentSize.width = tileWidth;
	contentSize.height = tileHeight;
	this->setContentSize(contentSize);
	//_tiles = Array::createWithCapacity(width * height);

	this->setAnchorPoint(Point(0,0));
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
	tile->setPosition(x * (_tileWidth) , y * (_tileHeight));
	log("content: %f, %f, position: %f, %f", contentSize.width, contentSize.height, tile->getPosition().x, tile->getPosition().y);
	tile->setAnchorPoint(Point(0, 0));
	this->addChild(tile);
	return true;
}

DemoBlock * DemoBlock::create(int width, int height, float tileWidth, float tileHeight)
{
	DemoBlock *db = new DemoBlock(width, height, tileWidth, tileHeight);
	if(db && db->init())
	{
		db->autorelease();
		return db;
	}
	return nullptr;
}

int DemoBlock::getResistance()
{
	return _resistance;
}

void DemoBlock::setResistance(int resistance)
{
	_resistance = resistance;
}