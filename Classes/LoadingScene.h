#pragma once

/*
EliminatePest��������Ϸ��Դ���س���ģ��
����
1.LoadingScene��
��;�����ڹ�����Ϸ��Դ���س���
*/

#include "QE.h"

class LoadingScene : public Layer
{
QE_CreateSceneFromLayer_H(LoadingScene);
public:
	void startScene();
};