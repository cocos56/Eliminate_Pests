#pragma once

/*
EliminatePest所属的开始游戏场景模块
含：
1.StartGameScene类
用途：用于管理开始游戏场景
*/

#include "QE.h"

//游戏菜单类
class StartGameScene :public Layer
{
QE_CreateSceneFromLayer_H(StartGameScene);

public:
	ProgressTimer *_progress;//进度条
	                        /*ProgressTimer是Node的子类。 该类根据百分比来渲染显示内部
		                    的Sprite对象。 变化方向包括径向，水平或者垂直方向。 */
	float _progressInterval;//进度条更新次数
	int _sourceCount;//用来保存游戏需要加载的资源总数
	Menu* menu;//按钮菜单

	Sprite* helpBg;//帮助面板

public:
	void menuCloseCallback();
	void start();
	void helpLayer();
	void helpBack();
};