#pragma once

/*
EliminatePest��������Ϸ�����µ���Ϸ��ɫ���µ�ս���߲���ģ��
����
1.FightingVegetable��
��;�����ڸ���Ϸ�е�ս���߲˽�ɫ�ṩ֧��
*/

#include "QE.h"

//ǰ������AimedVegetable��
class AimedVegetable;

class FightingVegetable : public GameRole
{
public:
	FightingVegetable();

	static void updateObjsFightEffect();
	static void updateObjsGrouthAnimate();
	void updateObjGrouthAnimate();
	void initGrouthAnimate();
	//�ж�����ֲ���Ƿ��ܹ�����Ŀ��ֲ��
	static void isProtecting(AimedVegetable* target);
	static void isProtecting(FightingVegetable* target);
	//�������ɵ����ж����ָ���б�
	static vector<FightingVegetable*> _objsList;

	//��д���ԣ���ʱ����ֲ��ģ�ս����Ч��������ʵ�֣�δ���ö���֡
	ParticleSystemQuad* fightEffectPlayer;
	void initFightEffect();
	void updateFightEffect();

private:
	//��ʱ������ֲ�������ֵ��������
	int _life = -1;
	void playDeathAnimate() { /*����ֲ����ʱ���������������*/ };
	void underAttackAction() { /*����ֲ����ʱ�������ܵ����������*/ };
	static bool isProtecting(Coordinate a, Coordinate b);
};
