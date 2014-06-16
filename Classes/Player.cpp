/*
    �ļ�����    Player.h
    �衡����    ��Ϸ���ǵ�ʵ��
    �����ˣ�    ������ (���ͣ�http://blog.csdn.net/haomengzhu)

    �������ڣ�   2013.12.05
*/
#include "Player.h"
#define ACCELERATION 0.05f

Player::~Player(){

    CC_SAFE_RELEASE(_rideAnimation);
    CC_SAFE_RELEASE(_floatAnimation);
}

Player::Player(float scaleRate) {
	_screenSize = CCDirector::sharedDirector()->getWinSize();
	_floatingTimerMax = 2;
	_floatingTimer = 0;
	_speed = PLAYER_INITIAL_SPEED;
	_maxSpeed = PLAYER_INITIAL_SPEED;
	_floating = false;
	_nextPosition = Point::ZERO;
	_nextPosition.y = _screenSize.height * 0.8f;
	_state = kPlayerMoving;
	_jumping = false;
	_hasFloated = false;
	_scaleRate = scaleRate;
}

Player * Player::create (float scaleRate) {

	Player * player = new Player(scaleRate);
	if (player && player->initWithSpriteFrameName("player_1.png")) {
		player->autorelease();
		player->setSize();
		player->initPlayer();
		return player;
	}
	CC_SAFE_DELETE(player);
	return NULL;
}


void Player::update (float dt) {

	//���ٶȵ����Ȼ������
	if (_speed + ACCELERATION <= _maxSpeed) {
		_speed += ACCELERATION;
	} else {
		_speed = _maxSpeed;
	}

	_vector.x = _speed;

	//CCLog("play state:%d",_state);

	switch (_state) {
	case kPlayerMoving:
		_vector.y -= SOLID_GRAVITY;
		if (_hasFloated) 
			_hasFloated = false;
		break;

	case kPlayerFalling:

		if (_floating ) {
			_vector.y -= FLOATNG_GRAVITY;
			_vector.x *= FLOATING_FRICTION;

		} else {
			_vector.y -= SOLID_GRAVITY;
			_vector.x *= AIR_FRICTION;
			_floatingTimer = 0;
		}
		break;

	case kPlayerDying:
		_vector.y -= SOLID_GRAVITY;
		_vector.x = -_speed;
		this->setPositionX(this->getPositionX() + _vector.x);
		break;

	}

	if (_jumping) {
		_state = kPlayerFalling;
		_vector.y += PLAYER_JUMP * 0.25f;
		if (_vector.y > PLAYER_JUMP ) 
			_jumping = false;
	}

	if (_vector.y < -TERMINAL_VELOCITY) 
		_vector.y = -TERMINAL_VELOCITY;

	_nextPosition.y = this->getPositionY() + _vector.y;
	if (_vector.x * _vector.x < 0.01) 
		_vector.x = 0;
	if (_vector.y * _vector.y < 0.01) 
		_vector.y = 0;

	if (_floating) {
		_floatingTimer += dt;
		if (_floatingTimer > _floatingTimerMax) {
			_floatingTimer = 0;
			this->setFloating(false);
		}
	}
}

//��������
void Player::reset () {

	_speed = PLAYER_INITIAL_SPEED;
	_maxSpeed = PLAYER_INITIAL_SPEED;
	_vector = Point::ZERO;
	this->setFloating(false);
	this->setRotation(0);
	_nextPosition.y = _screenSize.height * 0.6f;
	this->setPosition(Point( _screenSize.width * 0.2f, _nextPosition.y ));
	_state = kPlayerMoving;
	_jumping = false;
	_hasFloated = false;
}

//�����½�����
void Player::setFloating (bool value) {

	if (_floating == value) 
		return;

	if (value && _hasFloated) 
		return;

	_floating = value;

    this->stopAllActions();

	if (value) {
		_hasFloated = true;
        this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("player_float.png"));
        this->runAction(_floatAnimation);
		_vector.y += PLAYER_JUMP * 0.5f;
    } else {
        
        this->runAction(_rideAnimation);
	} 
}

//��ʼ������
void Player::initPlayer () {

	//����ê��
	this->setAnchorPoint(Point(0.5f, 1.0f));
	this->setPosition(Point(_screenSize.width * 0.2f, _nextPosition.y));
	this->setScale(_scaleRate);

	_height = this->getContentSize().height * _scaleRate * 0.95; //ȥ��sprite����İױ�
	_width = this->getContentSize().width * _scaleRate;

	//_height = 228;
	//_width = 180;
	//_height = 50;
	//_width = 50;
    Animation* animation;
	//����һ���հ׵�����֡������Ϣ
    animation = Animation::create();

	//CCSpriteFrame��Ӧ�ľ���֡����CCSpriteFrame��ӵ�CCAnimation���ɶ������ݣ�
	//��CCAnimation����CCAnimate���������յĶ�������������������CCSpriteִ�����������
    CCSpriteFrame * frame;
    int i;
	//����3֡��������forѭ������Ӧ������ͼ���뵽������
    for(i = 1; i <= 3; i++) {
        char szName[100] = {0};
        sprintf(szName, "player_%i.png", i);
        frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(szName);
        animation->addSpriteFrame(frame);
    }
    
	//����ÿ��֡��ʱ����
    animation->setDelayPerUnit(0.2f / 3.0f);
	//���ö����������Ƿ�������֡��Ϣ
    animation->setRestoreOriginalFrame(false);
	//����ѭ�����Ŵ��� (-1:����ѭ��)
    animation->setLoops(-1);
	//�����������Ϣ����һ������֡����
    _rideAnimation = CCAnimate::create(animation);
	//�����������
    _rideAnimation->retain();
    
	//CCFiniteTimeAction���������޴�ִ���ࣨ����Ҳ���Խ�˳��ִ����ɣ��Ļ���
	//CCSequence����һ����������
	//CCEaseInOut������Ӧ���ٶ����ı��ٶ���������һΪһ�����ٶ�����������Ϊ�ٶ�
    FiniteTimeAction* easeSwing = CCSequence::create(
           CCEaseInOut::create(CCRotateTo::create(0.8f, -10), 2),
           CCEaseInOut::create(CCRotateTo::create(0.8f, 10), 2),
           NULL);
    _floatAnimation = CCRepeatForever::create( (ActionInterval*) easeSwing );
    _floatAnimation->retain();
    
    this->runAction(_rideAnimation);
}
