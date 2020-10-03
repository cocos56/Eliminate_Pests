#pragma once

/*
EliminatePest所属的游戏场景下的游戏角色类下的战斗蔬菜类模块
含：
1.FightingVegetable类
用途：用于给游戏中的战斗蔬菜角色提供支持
*/

#include "QE.h"

//前向声明AimedVegetable类
class AimedVegetable;

class FightingVegetable : public GameRole
{
public:
	FightingVegetable();

	static void updateObjsFightEffect();
	static void updateObjsGrouthAnimate();
	void updateObjGrouthAnimate();
	void initGrouthAnimate();
	//判断驱虫植株是否能够保护目标植株
	static void isProtecting(AimedVegetable* target);
	static void isProtecting(FightingVegetable* target);
	//本类生成的所有对象的指针列表
	static vector<FightingVegetable*> _objsList;

	//重写属性，暂时驱虫植物的（战斗）效果由粒子实现，未采用动画帧
	ParticleSystemQuad* fightEffectPlayer;
	void initFightEffect();
	void updateFightEffect();

private:
	//暂时是驱虫植物的生命值是无穷大的
	int _life = -1;
	void playDeathAnimate() { /*驱虫植物暂时不考虑死亡的情况*/ };
	void underAttackAction() { /*驱虫植物暂时不考虑受到攻击的情况*/ };
	static bool isProtecting(Coordinate a, Coordinate b);
};
