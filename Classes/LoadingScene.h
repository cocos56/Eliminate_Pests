#pragma once

/*
EliminatePest所属的游戏资源加载场景模块
含：
1.LoadingScene类
用途：用于管理游戏资源加载场景
*/

#include "QE.h"

class LoadingScene : public Layer
{
QE_CreateSceneFromLayer_H(LoadingScene);
public:
	void startScene();
};