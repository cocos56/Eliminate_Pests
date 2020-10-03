#include "Vegetable.h"

int Vegetable::order = 0;

void Vegetable::plantAimedVegetables()
{
	order++;
	//初始化并生成一个目标植物
	new AimedVegetable;

	//CCLOG("num = %d", GameScene::_plantC.num);
}

void Vegetable::plantFightingVegetables(const string name)
{
	order++;
	//初始化要种植的驱虫植物属性
	CurrentLevelData::initFightingVegetableType(name);
	//初始化并生成驱虫植物
	new FightingVegetable;
}