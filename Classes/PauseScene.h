#pragma once

/*
EliminatePest��������Ϸ��ͣ����ģ��
����
1.PauseScene��
��;�����ڹ�����Ϸ��ͣ����
*/

#include "QE.h"

class PauseScene
{
public:
	static Layer* _layer;
	static Size winSize;

public:
	static Scene* createWinScene();
	static Scene* createPauseScene();
	static Scene* createFailScene();

	static void addBg();

	//create a blank scene
	static Scene* createScene();
	static void resume(Ref* sender);

	static void back();
};
