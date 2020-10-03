#pragma once

/*
EliminatePest所属的游戏场景下的游戏角色类下的目标蔬菜类模块
含：
1.AimedVegetable类
用途：用于给游戏中的目标蔬菜角色提供支持
*/


#include "QE.h"
//前向声明
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

	//本类生成的所有对象的指针列表
	static vector<AimedVegetable*> _objsList;
	//成熟目标植物的总数量
	static int _ripeNum;
	//
	bool _isAddToRipeNum = false;
	//未成熟目标植物的列表
	static vector< AimedVegetable*> _unripeList;
	static void addRipeNumFromUnripeList();
	void getPest();
	Pest* _pest=nullptr;
	vector<FightingVegetable*> _fightingVegetables;

	void playDeathAnimate();
private:
	void updateFightEffect() { /*目标植物暂时不考虑参与战斗的情况*/ };
	void initFightEffect() { /*目标植物暂时不考虑参与战斗的情况*/ };
};