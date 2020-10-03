#pragma once

/*
EliminatePest所属的游戏场景下的层下的时间层类模块
含：
1.TimeLayer类
用途：用于管理时间，管理线程，管理整个游戏场景数据的变化
*/

#include "QE.h"

class TimeLayer : public Layer
{
QE_CreateLayerFromLayer_H(TimeLayer);
public:
	void myUpdate(float f);
	LabelTTF* getLabel(int x);
	void updateLabel();
	void win();
	void fail();

	LabelTTF *_countTimeLabel, *_aimedVegetableLabel;
};