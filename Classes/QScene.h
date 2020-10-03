#pragma once

/*
Quick Engine�������ٳ���ģ��
����
1.QScene��
��;�����ڿ��ٹ�����
*/


#include "cocos2d.h"
USING_NS_CC;
#include "QDesignMode.h"

#define QE_winSize Size(1024, 576);
#define QE_get_winSize Size winSize = QE_winSize;

#define QE_CreateSceneFromLayer_CPP(TYPE) \
Scene* TYPE::createScene() \
{ \
	Scene* scene = Scene::create(); \
	Layer* layer = TYPE::create(); \
	scene->addChild(layer); \
	return scene; \
} \
 \
bool TYPE::init() \
{ \
	if (!Layer::init()) \
	{ \
		return false; \
	} \
vector<string> paths;

#define QE_CreateSceneFromLayer_H(TYPE) \
public: \
static Scene* createScene(); \
virtual bool init(); \
CREATE_FUNC(TYPE); \
QE_get_winSize

class QScene
{
public:
	//will save now scene to pause.png
	static void saveNowSceneToFile();
};