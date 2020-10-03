#pragma once

/*
Quick Engineģ��

�汾��V1.0 for ElimatePests

QE��Quick Engine���������棩��飺
����Cocos2d-x 3.17.1��C++ 17���������������ܶ����������ĸ����ԡ�
QE�������Ϊ���Ż�Ĭ�ϵĲ���ֵ�������б�ʹԭ����Ҫ���д��������ɵĹ��ܣ�����ֻ��Ҫһ�д��������ɡ�

���磺
1.�������ɱ������顢����ê���λ�þ�Ϊ��0, 0��������ӵ���ǰ�ڵ㣬ֻ��Ҫ����һ��������ˡ�
	�ǵð���Դ�ĳ�bg.png��
	���á�QE_addBgSpriteToThis������꼴�ɣ�������ڴ��룬Ҳ����Ҫ�����κβ���

2.�������ɲ˵���������ͼƬ�����Լ�һ���ɵ��ö��󼴿ɡ�

3.����ͷ�ļ�ֻ��Ҫ���������һ�£�Ȼ������Ӧ��ͷ�ļ����ٰ���һ�´�ͷ�ļ��Ϳ����ˡ�
�����������ң�������������Ч�����Դ����ٰ�����ͷ�ļ�������
*/

//��
//CB = callback
#define QE_CB0(Type, Fun, ...) std::bind(&Type::Fun,this, ##__VA_ARGS__)
//CBWT = callback with target
#define QE_CBWT0(Type, Fun, targert, ...) std::bind(&Type::Fun,targert, ##__VA_ARGS__)
//#define CC_CALLBACK_0(__selector__,__target__, ...) std::bind(&__selector__,__target__, ##__VA_ARGS__)
#define QE_CALLBACK_1(Type,Fun) CC_CALLBACK_1(Type::Fun, this)

//C++
using namespace std;

//Cocos2d-x
#include "cocos2d.h"
USING_NS_CC;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

//���ģʽ
#include "QDesignMode.h"

//QE
#include "QType.h"
#include "QScene.h"
#include "QLayer.h"
#include "QMenu.h"
#include "QSprite.h"
#include "QFileUtils.h"
#include "QAnimate.h"
#include "QObject.h"
#include "QJson.h"
#include "QTMX.h"

//User
#include "LoadingScene.h"
#include "StartGameScene.h"
#include "SelectLevelScene.h"

#include "GameRole.h"
#include "Pest.h"
#include "FightingVegetable.h"
#include "AimedVegetable.h"
#include "TimeLayer.h"
#include "Vegetable.h"
#include "PauseScene.h"
#include "GameScene.h"
#include "CurrentLevelData.h"