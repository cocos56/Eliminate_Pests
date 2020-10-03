#pragma once

/*
EliminatePest所属的游戏场景下的游戏角色类下的害虫类模块
含：
1.Pest类
用途：用于给游戏中的害虫角色提供支持
*/

#include "QE.h"

//前向声明
class FightingVegetable;

class Pest : public GameRole
{
public:
	Pest();
	//本类生成的所有对象的指针列表
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