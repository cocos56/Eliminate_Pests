#pragma once

/*
EliminatePest�����Ŀ�ʼ��Ϸ����ģ��
����
1.StartGameScene��
��;�����ڹ���ʼ��Ϸ����
*/

#include "QE.h"

//��Ϸ�˵���
class StartGameScene :public Layer
{
QE_CreateSceneFromLayer_H(StartGameScene);

public:
	ProgressTimer *_progress;//������
	                        /*ProgressTimer��Node�����ࡣ ������ݰٷֱ�����Ⱦ��ʾ�ڲ�
		                    ��Sprite���� �仯�����������ˮƽ���ߴ�ֱ���� */
	float _progressInterval;//���������´���
	int _sourceCount;//����������Ϸ��Ҫ���ص���Դ����
	Menu* menu;//��ť�˵�

	Sprite* helpBg;//�������

public:
	void menuCloseCallback();
	void start();
	void helpLayer();
	void helpBack();
};