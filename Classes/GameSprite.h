/*
    �ļ�����    GameSprite.h
    �衡����    ��Ϸ�ж����һЩ������
    �����ˣ�    ������ (���ͣ�http://blog.csdn.net/haomengzhu)

    �������ڣ�   2013.12.05
*/
#ifndef __GAMESPRITE_H__
#define __GAMESPRITE_H__

#include "cocos2d.h"


USING_NS_CC;
enum {

	kBackground,//������
	kMiddleground,//�м��
	kForeground //���ϲ�
};
enum {
    kSpritePlayer,
    kSpriteTerrain,
    kSpriteBlock,
    kSpriteChimney,
    kSpritePuff
};

class GameSprite : public Sprite {
protected:
	CCSize _screenSize;

public:

	//�������������ֱ�Ӷ���Ĭ�ϵ�get/set����
	CC_SYNTHESIZE(CCPoint, _nextPosition, NextPosition);

	CC_SYNTHESIZE(float, _width, Width);

	CC_SYNTHESIZE(float, _height, Height);

	CC_SYNTHESIZE(Point, _vector, Vector);

	GameSprite(void);
	~GameSprite(void);

	//�����麯����ֻ��һ���ӿ�
	inline virtual void place () { this->setPosition(_nextPosition); };

    inline virtual float radius () {
        return _width * 0.5f;
    }
	inline void setSize() {
		_width = this->boundingBox().size.width;
		_height = this->boundingBox().size.height;
	}
};

#endif // __GAMESPRITE_H__

