#pragma once

/*
EliminatePest所属的游戏暂停场景模块
含：
1.PauseScene类
用途：用于管理游戏暂停场景
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
