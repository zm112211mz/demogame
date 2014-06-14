#include "BlockFactory.h"

static BlockFactory *bf = nullptr;

BlockFactory::BlockFactory(void)
{
	init();
}


BlockFactory::~BlockFactory(void)
{
}

DemoBlock * BlockFactory::getBlock(int width, int height, blockType type)
{
	if(bf == nullptr)
	{
		bf = new BlockFactory();
	}
	return bf->generateBlock(width, height, type);
	return NULL;
}

void BlockFactory::init()
{
	_tileSample = Sprite::createWithSpriteFrameName("building_1.png");
	_roofSample = Sprite::createWithSpriteFrameName("roof_1.png");

	_tile1 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("building_1.png");
	_tile2 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("building_2.png");
	_tile3 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("building_3.png");
	_tile4 = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("building_4.png");

	_roof1 = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("roof_1.png");
	_roof2 = SpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("roof_2.png");

	_tileWidth = _tileSample->getContentSize().width;
	_tileHeight = _tileSample->getContentSize().height;

	_roofWidth = _roofSample->getContentSize().width;
	_roofHeight = _roofSample->getContentSize().height;
}

DemoBlock *BlockFactory::generateBlock(int width, int height, blockType type)
{
	DemoBlock *db = DemoBlock::create(width , height, _tileWidth, _tileHeight);
	if(db == nullptr)
	{
		return NULL;
	}

	for(int x = 0; x < width; x++)
	{
		for(int y = 0; y < height; y++)
		{
			Sprite *sprite = Sprite::createWithSpriteFrame(_tile1);
			//Sprite *sprite = Sprite::create("CloseNormal.png");
			db->addTile(x, y, sprite);
		}
	}

	return db;
}