#pragma once

/*
EliminatePest所属的游戏关卡选择场景模块
含：
1.SelectLevelScene类
用途：用于管理游戏关卡选择场景
*/

#include "QE.h"

#include "ui/CocosGUI.h"
using namespace ui;

//关卡选择类
class SelectLevelScene :public Layer
{
QE_CreateSceneFromLayer_H(SelectLevelScene);
public:
	static int _levelIndex;
	static vector<string> _levelsName;
	static string _levelName;
	//开始游戏
	static void start();
	MenuItem* _start;

	void initMenu();

	//获取用户可选的关卡数。
	bool isLevelLocked(int level);
	bool isPlayBgMusic();
	void setPlayMusicStatus(bool status);

	static PageView* _pageView;
	void initPageView();
	
	void back();
	void pageViewCallBack(Ref* pSender, PageView::EventType type);
	MenuItem* _rightSelect, *_leftSelect, *_playBgMusic, *_stopBgMusic;
	void showSelect();
};

