#include "Vegetable.h"

int Vegetable::order = 0;

void Vegetable::plantAimedVegetables()
{
	order++;
	//��ʼ��������һ��Ŀ��ֲ��
	new AimedVegetable;

	//CCLOG("num = %d", GameScene::_plantC.num);
}

void Vegetable::plantFightingVegetables(const string name)
{
	order++;
	//��ʼ��Ҫ��ֲ������ֲ������
	CurrentLevelData::initFightingVegetableType(name);
	//��ʼ������������ֲ��
	new FightingVegetable;
}