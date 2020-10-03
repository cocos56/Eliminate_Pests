#pragma once

/*
Quick Engine�������پ���ģ��
����
1.QSprite��
��;�����ڿ��ٹ�����
*/


#include "QE.h"

class QSprite
{
	QE_SINGLETON_H(QSprite);

public:
	static Sprite* createBgSprite();
	static Sprite* createBgSprite(const std::string& filename);
};

#define QE_addBgSpriteToThis addChild(QSprite::createBgSprite());