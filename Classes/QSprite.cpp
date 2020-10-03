#include "QSprite.h"

QE_SINGLETON_CPP(QSprite);

Sprite* QSprite::createBgSprite()
{
	return createBgSprite("bg.png");
}

Sprite* QSprite::createBgSprite(const std::string& filename)
{
	//��ȡ���ڴ�С
	Size size = Director::getInstance()->getWinSize();

	//������������
	Sprite* bg = Sprite::create(filename);

	//������
	float scaleX = size.width / bg->getContentSize().width;
	float scaleY = size.height / bg->getContentSize().height;
	bg->setScale(scaleX, scaleY);

	//����λ��
	bg->setPosition(Vec2(size.width / 2, size.height / 2));
	return bg;
}
