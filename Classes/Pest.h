#pragma once

/*
EliminatePest��������Ϸ�����µ���Ϸ��ɫ���µĺ�����ģ��
����
1.Pest��
��;�����ڸ���Ϸ�еĺ����ɫ�ṩ֧��
*/

#include "QE.h"

//ǰ������
class FightingVegetable;

class Pest : public GameRole
{
public:
	Pest();
	//�������ɵ����ж����ָ���б�
	static void updateObjsGrouthAnimate();
	void updateObjGrouthAnimate();
	void initGrouthAnimate();
	static vector<Pest*> _objsList;
	void underAttackAction(vector<FightingVegetable*>& _fightingVegetables);
	void underAttackAction(FightingVegetable* _fightingVegetable);

	string name;
	void playDeathAnimate();
	void initFightEffect();
	void updateFightEffect();
};