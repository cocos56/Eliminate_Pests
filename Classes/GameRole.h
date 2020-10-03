#pragma once

/*
EliminatePest��������Ϸ�����µ���Ϸ��ɫ���µ���Ϸ��ɫģ��
����
1.GameRole��
��;�����ڸ���Ϸ�еĽ�ɫ�ṩ֧�֣������࣬���뱻������̳в���ʵ��������
*/

#include "QE.h"

class GameRole
{
public:
	/*�������鷽����updateObjGrouthAnimate��initGrouthAnimate
	��playDeathAnimate��initFightEffect��updateFightEffect
	��������࣬�޷�ֱ�����ɶ��󣬿�����������̳�����Ȼ������������Ķ���
	ע�⣺�������ڼ̳�ʱӦ��д�����鷽����
	*/
	//ʣ������ʱ�䣨���������죩
	int _leftGrowingTime;
	//����������ÿ�룩
	int _attack;
	//����ֵ���㣩
	int _life = 6;
	//�Ƿ�������
	bool _isDied = false;
	//��������
	Coordinate _c;

	/*���ж���֡�뵱ǰ֡��ţ�Ȼ������QE��װ�õķ����Ϳ��Բ��Ŷ���*/
	//���гɳ�����֡
	vector<Sprite*> _growthFrames;
	//��ǰ�ɳ�֡�������
	int _growthFrameNum = 1;
	//�������ж������������֡
	void updateObjsGrouthAnimate() {};
	//���µ�ǰ�������������֡
	virtual void updateObjGrouthAnimate() = 0;
	//��ʼ����������
	virtual void initGrouthAnimate() = 0;
	//������������
	virtual void playDeathAnimate() = 0;
	//����ս������֡���
	vector<Sprite*> _fightFrames;
	//��ǰս��֡�������
	int _fightFrameNum = 1;
	//��ʼ��ս����Ч
	virtual void initFightEffect() = 0;
	//����ս����Ч
	virtual void updateFightEffect() = 0;
};