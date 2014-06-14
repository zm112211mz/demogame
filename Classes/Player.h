/*
    �ļ�����    Player.h
    �衡����    ��Ϸ�ж��������
    �����ˣ�    ������ (���ͣ�http://blog.csdn.net/haomengzhu)

    �������ڣ�   2013.12.05
*/
#ifndef __PLAYER_H__
#define __PLAYER_H__

//���ǳ�ʼ�ٶ�
#define PLAYER_INITIAL_SPEED 4
//#define PLAYER_JUMP 42
#define PLAYER_JUMP 15
#define SOLID_GRAVITY 1.3f
#define FLOATNG_GRAVITY 0.4f
#define TERMINAL_VELOCITY 70
#define FLOATING_FRICTION 0.98f
#define AIR_FRICTION 0.99f

#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;

typedef enum
{
	kPlayerMoving,//�������ƶ�
	kPlayerFalling,//�����ڽ���
	kPlayerDying//��������

} PlayerState; 

//���Ǽ̳�����Ϸ������
class Player : public GameSprite {
	Action * _rideAnimation;
	Action * _floatAnimation;
    float _speed;
	int _floatingTimerMax;
	float _floatingTimer;
	int _floatingInterval;
	bool _hasFloated;
	float _scaleRate;

	Size _screenSize;

	void initPlayer (void);

public:
	Player(float scaleRate);
	~Player(void);

	//�������������ֱ�Ӷ���Ĭ�ϵ�get/set����
	CC_SYNTHESIZE(PlayerState, _state, State);
	CC_SYNTHESIZE(bool, _inAir, InAir);
	CC_SYNTHESIZE_READONLY(bool, _floating, Floating);
	CC_SYNTHESIZE(bool, _jumping, Jumping);
	CC_SYNTHESIZE(float, _maxSpeed, MaxSpeed);

	static Player* create(float scaleRate);
	virtual void update (float dt);

	void setFloating (bool value);

	void reset (void);

	//����λ�õ�����ʵ��
	inline virtual void place () { 
		this->setPositionY( _nextPosition.y );
		if (_vector.x > 0 && this->getPositionX() < _screenSize.width * 0.2f) {
			this->setPositionX(this->getPositionX() + _vector.x);
			if (this->getPositionX() > _screenSize.width * 0.2f) {
				this->setPositionX(_screenSize.width * 0.2f);
			}
		}
	};

	//������X���ϵ�λ��[�����Ч��ײ]
	inline int left() {
		return this->getPositionX() - _width * 0.5f;
	}

	//������X���ϵ�λ��[�Ҳ���Ч��ײ]
	inline int right() {
		return this->getPositionX() + _width * 0.5f;
	}

	//������Y���ϵ�λ��
	inline int top() {
		return this->getPositionY();
	}

	//������Y���ϵ�λ�á��ײ���Ч��ײ��
	inline int bottom() {
		return this->getPositionY() - _height ;
	}

	//������һ��λ�õ����
	inline int next_left() {
		return _nextPosition.x - _width * 0.5f;
	}

	//������һ��λ�õ��Ҳ�
	inline int next_right() {
		return _nextPosition.x + _width * 0.5f;
	}

	//������һ��λ�õ��ϲ�
	inline int next_top() {
		return _nextPosition.y;
	}

	//������һ��λ�õĵײ�
	inline int next_bottom() {
		return _nextPosition.y - _height;
	}
};

#endif // __PLAYER_H__


