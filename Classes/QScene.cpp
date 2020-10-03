#include "QScene.h"

void QScene::saveNowSceneToFile()
{
	QE_get_winSize;
	TextureCache::getInstance()->removeUnusedTextures();
	//�൱�ڽ�ȡ��ͣ��һɲ�ǵ���Ϸ����ͼ�������������pause.png
	auto texture = RenderTexture::create(winSize.width, winSize.height);
	texture->begin();
	Director::getInstance()->getRunningScene()->visit();
	texture->end();
	texture->saveToFile("pause.png", Image::Format::PNG);
}