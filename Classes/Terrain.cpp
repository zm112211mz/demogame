#include "Terrain.h"
#include <algorithm>
#include "GameTypes.h"

int patterns[] = {1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3};
int widths[] = {2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4};
int heights[] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,3,3,3,3,3,3,4};
int types[] = {1,2,3,4,1,3,2,4,3,2,1,4,2,3,1,4,2,3,1,2,3,2,3,4,1,2,4,3,1,3,1,4,2,4,2,1,2,3};
int balktypes[] = {0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2};

vector<int> _blockPattern (patterns, patterns + sizeof(patterns) / sizeof(int));
vector<int> _blockWidths (widths, widths + sizeof(widths) / sizeof(int));
vector<int> _blockHeights (heights, heights + sizeof(heights) / sizeof(int));
vector<int> _blockTypes (types, types + sizeof(types) / sizeof(int));
vector<int> _balkTypes(balktypes, balktypes + sizeof(balktypes) / sizeof(int));

Terrain::~Terrain () {

	CC_SAFE_RELEASE(_blockPool);
	CC_SAFE_RELEASE(_blocks);
    CC_SAFE_RELEASE(_balkPool);
    CC_SAFE_RELEASE(_balks);
}

Terrain::Terrain()
	:_screenSize(Director::getInstance()->getWinSize())
	,_startTerrain(false)
	,_blockPoolIndex(0)
    ,_balkPoolIndex(0)
	,_currentPatternCnt(1)
	,_currentPatternIndex(0)
	,_currentTypeIndex(0)
	,_currentWidthIndex(0)
	,_currentHeightIndex(0)
	,_showGap(false)
{
}

Terrain* Terrain::create(float scaleRate) {
	Terrain * terrain = new Terrain();

	terrain->setScaleRate(scaleRate);
	//terrain->setScale(scaleRate);
	log("this sprite content: %f, %f; the screen: %f, %f",
		terrain->getContentSize().width,
		terrain->getContentSize().height,
		Director::getInstance()->getWinSize().width,
		Director::getInstance()->getWinSize().height);
	if (terrain && terrain->initWithSpriteFrameName("blank.png")) {
		terrain->setAnchorPoint(Point(0, 0));
		terrain->initTerrain();
		terrain->autorelease();
		return terrain;
	}
	CC_SAFE_DELETE(terrain);
	return NULL;
}

void Terrain::initTerrain() {
	_increaseGapInterval = 5000;
	_increaseGapTimer = 0;
	_gapSize = 2;

	_blockPool = __Array::createWithCapacity(20);
	_blockPool->retain();
    
    _balkPool = __Array::createWithCapacity(20);
    _balkPool->retain();

	//init object pools
	GameBlock * block;
	for (int i = 0; i < 20; i++) {
		block = GameBlock::create(this->_scaleRate);
		this->addChild(block);
		_blockPool->addObject(block);
	}
    
    Balk * balk;
    for (int i = 0; i < 20; i++) {
        balk = Balk::create();
        this->addChild(balk);
    }

	_blocks = Array::createWithCapacity(20);
	_blocks->retain();

	_minTerrainWidth = _screenSize.width * 1.5f;

	random_shuffle(_blockPattern.begin(), _blockPattern.end());
	random_shuffle(_blockWidths.begin(), _blockWidths.end());
	random_shuffle(_blockHeights.begin(), _blockHeights.end());

	this->addBlocks(0);
}

void Terrain::activateChimneysAt(Player *player) {
    int count = _blocks->count();
    
	GameBlock * block;
    for (int i = 0; i < count; i++) {
        
		block = (GameBlock *) _blocks->objectAtIndex(i);
        if (block->getType() == kBlockGap) 
			continue;

        if (block->getPuffing()) 
			continue;
                
        if ( this->getPositionX() + block->getPositionX() >= _screenSize.width * 0.2f &&
            this->getPositionX() + block->getPositionX() < _screenSize.width * 0.8f) {
            block->setPuffing(true);
        }
    }
}
void Terrain::checkCollision(Player *player) {

	//�������״̬������������
	if (player->getState() == kPlayerDying)
		return;

	//�����ܿ���
	int count = _blocks->count();
	GameBlock * block;
	//�Ƿ��ڿ���
	bool inAir = true;
	int i;

	for (i = 0; i < count; i++) {

		block = (GameBlock *) _blocks->objectAtIndex(i);
		if (block->getType() == kBlockGap)
			continue;
		
		//if within x, check y (bottom collision)
		//�����Ǻͷ����ڣ�����ʱ
		if (player->right() >= this->getPositionX() + block->left()
			&& player->left() <= this->getPositionX() + block->right()) {
            
			if (player->bottom() >= block->top() && player->next_bottom() <= block->top()
				&& player->top() > block->top()) {
				player->setNextPosition(ccp(player->getNextPosition().x, block->top() + player->getHeight()));
				player->setVector(ccp(player->getVector().x, 0));
				// Sets the rotation (angle) of the node in degrees
                player->setRotation(0.0);
                inAir = false;
                break;
				player->setRotation(0.0);
				inAir = false;
				break;
			}
		}
	}

	for (i = 0; i < count; i++) {
		block = (GameBlock *) _blocks->objectAtIndex(i);
		if (block->getType() == kBlockGap)
			continue;

		//now if within y, check x (side collision)
		//�Ҳ෿��ͻȻ����
		if ((player->bottom() < block->top() && player->top() > block->bottom())
			|| (player->next_bottom() < block->top() && player->next_top() > block->bottom())) {

			if (player->right() >= this->getPositionX() + block->getPositionX()
				&& player->left() < this->getPositionX() + block->getPositionX()) {

				player->setPositionX(this->getPositionX() + block->getPositionX() - player->getWidth() * 0.5f);
				player->setNextPosition(ccp(this->getPositionX() + block->getPositionX() - player->getWidth() * 0.5f, player->getNextPosition().y));
				player->setVector(ccp(player->getVector().x * -0.5f, player->getVector().y));
				//����װǽ����
				if (player->bottom() + player->getHeight() * 0.2f < block->top()) {
					player->setState(kPlayerDying);
					return;
				}

						break;
				}
		}
	}

	if (inAir)
	{
		//�����½�״̬
		player->setState(kPlayerFalling);
	}
	else
	{
		//����һֱ��ֲ״̬
		player->setState(kPlayerMoving);
		player->setFloating(false);
	}
}

void Terrain::move(float xMove) {
	if (xMove < 0)
		return;


	if (_startTerrain) {

		if (xMove > 0 && _gapSize < 5)
			_increaseGapTimer += xMove;

		if (_increaseGapTimer > _increaseGapInterval) {
			_increaseGapTimer = 0;
			_gapSize += 1;
		}
	}

	this->setPositionX(this->getPositionX() - xMove);

	GameBlock * block;
	block = (GameBlock *) _blocks->objectAtIndex(0);

	if (this->getPositionX() + block->getWidth() < 0) {

		_blocks->removeObjectAtIndex(0);
		_blocks->addObject(block);

		this->setPositionX(this->getPositionX() + block->getWidth());

		float width_cnt = this->getWidth() - block->getWidth() - ((GameBlock *) _blocks->objectAtIndex(0))->getWidth();
		this->initBlock(block);
		this->addBlocks(width_cnt);
	}
}

void Terrain::reset() {

	this->setPosition(ccp(0, 0));
	_startTerrain = false;

	int count = _blocks->count();
	GameBlock * block;
	int i = 0;
	int currentWidth = 0;
	for (i = 0; i < count; i++) {
		block = (GameBlock *) _blocks->objectAtIndex(i);
		this->initBlock(block);
		currentWidth += block->getWidth();
	}

	while (currentWidth < _minTerrainWidth) {
		block = (GameBlock *) _blockPool->objectAtIndex(_blockPoolIndex);
		_blockPoolIndex++;
		if (_blockPoolIndex == _blockPool->count()) {
			_blockPoolIndex = 0;
		}
		_blocks->addObject(block);
		this->initBlock(block);
		currentWidth += block->getWidth();
	}

	this->distributeBlocks();
	_increaseGapTimer = 0;
	_gapSize = 2;
}

void Terrain::addBlocks(int currentWidth) {

	GameBlock * block;
	while (currentWidth < _minTerrainWidth)
	{
		block = (GameBlock *) _blockPool->getObjectAtIndex(_blockPoolIndex);
		_blockPoolIndex++;
		if (_blockPoolIndex == _blockPool->count()) {
			_blockPoolIndex = 0;
		}
		this->initBlock(block);
		currentWidth +=  block->getWidth();
		_blocks->addObject(block);

	}

	this->distributeBlocks();
}

void Terrain::distributeBlocks() {
	int count = _blocks->count();

	GameBlock * block;
	GameBlock * prev_block;
	int i;

	for (i = 0; i < count; i++) {
		block = (GameBlock *) _blocks->getObjectAtIndex(i);
		if (i != 0) {
			prev_block = (GameBlock *) _blocks->getObjectAtIndex(i - 1);
			block->setPositionX(prev_block->getPositionX() + prev_block->getWidth());
		}
		else
		{
			block->setPositionX(0);
		}
	}
}

void Terrain::initBlock(GameBlock * block) {

	int blockWidth;
	int blockHeight;

	//�������ڵĽ�������������
	int type = _blockTypes[_currentTypeIndex];
	_currentTypeIndex++;

	if (_currentTypeIndex == _blockTypes.size()) {
		_currentTypeIndex = 0;
	}

	//check if min distance reached;������ƿ�ʼ
	if (_startTerrain) {

		//�Ƿ���������
		if (_showGap) {

			int gap = rand() % _gapSize;
			if (gap < 2) 
				gap = 2;

			block->setupBlock(gap, 0, kBlockGap, _scaleRate);
			_showGap = false;

		}
		else {

			blockWidth = _blockWidths[_currentWidthIndex];

			_currentWidthIndex++;
			if (_currentWidthIndex == _blockWidths.size()) {
				random_shuffle(_blockWidths.begin(), _blockWidths.end());
				_currentWidthIndex = 0;
			}

			if (_blockHeights[_currentHeightIndex] != 0) {

				//change height of next block
				blockHeight = _blockHeights[_currentHeightIndex];
				//if difference too high, decrease it
				if (blockHeight - _lastBlockHeight > 2 && _gapSize == 2) {
					blockHeight = 1;
				}

			}
			else {
				blockHeight = _lastBlockHeight;
			}
			_currentHeightIndex++;
			if (_currentHeightIndex == _blockHeights.size()) {
				_currentHeightIndex = 0;
				random_shuffle(_blockHeights.begin(), _blockHeights.end());

			}

			block->setupBlock(blockWidth, blockHeight, type, _scaleRate);
			_lastBlockWidth = blockWidth;
			_lastBlockHeight = blockHeight;

			//select next block series pattern
			_currentPatternCnt++;
			if (_currentPatternCnt > _blockPattern[_currentPatternIndex]) {
				_showGap = true;
				//start new pattern
				_currentPatternIndex++;
				if (_currentPatternIndex == _blockPattern.size()) {
					random_shuffle(_blockPattern.begin(), _blockPattern.end());
					_currentPatternIndex = 0;
				}
				_currentPatternCnt = 1;
			}
		}

		//terrain is not being changed yet
	} else {
		_lastBlockHeight = 2;
		_lastBlockWidth = rand() % 2 + 2;
		block->setupBlock(_lastBlockWidth, _lastBlockHeight, type, _scaleRate);
	}
}
