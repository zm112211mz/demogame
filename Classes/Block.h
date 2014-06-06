/*
    �ļ�����    Block.h
    �衡����    ��Ϸ�ж���Ľ�����ͷ�ļ�
    �����ˣ�    ������ (���ͣ�http://blog.csdn.net/haomengzhu)

    �������ڣ�   2013.12.05
*/
#ifndef __BLOCK_H__
#define __BLOCK_H__



#include "cocos2d.h"
#include "GameSprite.h"

USING_NS_CC;


enum {
	kWallTile,//ǽ
	kRoofTile,//�ݶ�
	kChimney //�̴�
};

enum  {
	kBlockGap,//����
	kBlock1,
	kBlock2,
	kBlock3,
	kBlock4

};

//������
class Block : public GameSprite {

	//��Ļ���
	CCSize _screenSize;

	int _tileWidth;
	int _tileHeight;
	int _puffIndex;

	CCSpriteFrame * _tile1;
	CCSpriteFrame * _tile2;
	CCSpriteFrame * _tile3;
	CCSpriteFrame * _tile4;

	CCSpriteFrame * _roof1;//�ݶ�1
	CCSpriteFrame * _roof2;//�ݶ�2

	CCArray * _wallTiles;
	CCArray * _roofTiles;

	CCAction * _puffSpawn;
	CCAction * _puffMove;
    CCAction * _puffFade;
    CCAction * _puffScale;
    CCAction * _puffAnimation;

	void initBlock(void);
    void createPuff(void);
public:

	CC_SYNTHESIZE(int, _type, Type);

	//����һ����Ա����_puffing�Լ�getfunName������û��set������getfunName������ʵ��Ҫ�Լ���
	CC_SYNTHESIZE_READONLY(bool, _puffing, Puffing);

	//������Ա�������飺�̴�
	CC_SYNTHESIZE(CCArray *, _chimneys, Chimneys);

	Block();
	~Block();

	static Block * create();
	void setupBlock (int width, int height, int type);
	void setPuffing (bool value);
	void hidePuffs();

	inline virtual int left() {
		return this->getPositionX();
	}

	inline virtual int right() {
		return this->getPositionX() + _width;
	}

	inline virtual int top() {
		return this->getHeight();
	}

	inline virtual int bottom() {
		return 0;
	}


};

#endif // __BLOCK_H__
