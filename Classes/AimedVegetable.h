#pragma once

/*
EliminatePest��������Ϸ�����µ���Ϸ��ɫ���µ�Ŀ���߲���ģ��
����
1.AimedVegetable��
��;�����ڸ���Ϸ�е�Ŀ���߲˽�ɫ�ṩ֧��
*/


#include "QE.h"
//ǰ������
class Pest;
class FightingVegetable;

class AimedVegetable : public GameRole
{
public:
	AimedVegetable();

	static void updateObjsGrouthAnimate();
	static void updateObjsStatus();
	void updateObjStatus();
	bool isUnderProtecting();
	void updateObjGrouthAnimate();
	void initGrouthAnimate();
	void underAttackAction();

	//�������ɵ����ж����ָ���б�
	static vector<AimedVegetable*> _objsList;
	//����Ŀ��ֲ���������
	static int _ripeNum;
	//
	bool _isAddToRipeNum = false;
	//δ����Ŀ��ֲ����б�
	static vector< AimedVegetable*> _unripeList;
	static void addRipeNumFromUnripeList();
	void getPest();
	Pest* _pest=nullptr;
	vector<FightingVegetable*> _fightingVegetables;

	void playDeathAnimate();
private:
	void updateFightEffect() { /*Ŀ��ֲ����ʱ�����ǲ���ս�������*/ };
	void initFightEffect() { /*Ŀ��ֲ����ʱ�����ǲ���ս�������*/ };
};