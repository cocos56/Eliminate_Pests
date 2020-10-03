#pragma once

/*
EliminatePest所属的游戏场景下的层下的蔬菜模块
含：
1.Vegetable类
用途：用于管理点击种植蔬菜按钮后的操作
*/

#include "QE.h"

class Vegetable
{
public:
	static int order;
	static void plantAimedVegetables();
	static void plantFightingVegetables(const string name);
};