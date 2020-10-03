#pragma once

/*
EliminatePest所属的游戏场景下的当前关卡数据模块
含：
1.PestType类
用途：生成的对象可用于记录不同害虫类型的属性
2.AimedVegetableType类
用途：生成的对象可用于记录不同目标蔬菜类型的属性
3.FightingVegetableType类
用途：生成的对象可用于记录不同战斗蔬菜类型的属性
4.CurrentLevelData类
用途：用于管理当前关卡的数据
*/

#include "QE.h"

class PestType
{
public:
	string name;
	int hp, attack, maturingAge;
};

class AimedVegetableType
{
public:
	string name;
	int hp, maturingAge, pestAppearingTime;
};

class FightingVegetableType
{
public:
	string name;
	int attack, maturingAge;
};

class CurrentLevelData
{
	QE_SINGLETON_H(CurrentLevelData);
public:
	//本关属性
	//time为本关通关倒计时，winNum为本关胜利需要成功收获的熟菜数
	static int _time, _winNum;
	static vector<PestType> _pestTypes;
	static PestType _pestType;
	static vector<FightingVegetableType> _fightingVegetableTypes;
	static FightingVegetableType _fightingVegetableType;
	static void initFightingVegetableType(const string name);
	static AimedVegetableType _aimedVegetableType;

public:
	//JSON文件内容
	static void initGameLevelData(string levelName);
	void getLevelValue(JValue& level);
	void initAimedVegetableType(JValue& aimedVegetableType);
	void initPestTypes(JValue& pestTypes);
	void initFightingVegetableTypes(JValue& fightingVegetableTypes);
public:
	static JDoc document;
};
