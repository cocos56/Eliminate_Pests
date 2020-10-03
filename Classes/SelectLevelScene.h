#pragma once

/*
EliminatePest��������Ϸ�ؿ�ѡ�񳡾�ģ��
����
1.SelectLevelScene��
��;�����ڹ�����Ϸ�ؿ�ѡ�񳡾�
*/

#include "QE.h"

#include "ui/CocosGUI.h"
using namespace ui;

//�ؿ�ѡ����
class SelectLevelScene :public Layer
{
QE_CreateSceneFromLayer_H(SelectLevelScene);
public:
	static int _levelIndex;
	static vector<string> _levelsName;
	static string _levelName;
	//��ʼ��Ϸ
	static void start();
	MenuItem* _start;

	void initMenu();

	//��ȡ�û���ѡ�Ĺؿ�����
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

