#pragma once

/*
EliminatePest��������Ϸ�����µĲ��µ�ʱ�����ģ��
����
1.TimeLayer��
��;�����ڹ���ʱ�䣬�����̣߳�����������Ϸ�������ݵı仯
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