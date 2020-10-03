#pragma once

/*
EliminatePest所属的游戏场景下的游戏场景模块
含：
1.GameScene类
用途：用于管理游戏场景
*/

#include "QE.h"

class GameScene :public Layer
{
QE_CreateSceneFromLayer_H(GameScene);
public:
	static void plant(Coordinate c);
	static void showPlantItems(bool isShow = false);

public:
	static Coordinate _plantC;
	vector<Coordinate> _coordinates;
	static vector<MenuItem*> _plantItems;
	static Layer* _vegetableLayer, * _pestLayer, * _particleLayer, *_plantLayer, *_timeLayer;
	//暂停游戏精灵菜单项
	static MenuItem* _pause_item;

	//重新初始化变量，用于按了返回再进入游戏，需要对之前的一些自定义变量做清理以及重新初始化
	void reinitVar();
	//是否需要重新初始化（启动游戏后第一次进入游戏场景不需要，返回到其他场景再次进入游戏场景时需要）
	static bool _shouldReinitVar;
	//初始化种植菜单项的坐标
	void initCoordinates();
	//初始化所有菜单项
	void initMenuItems();
	//初始化种植植物的菜单项层
	void initPlantItems();
	//初始化所有层
	void initLayers();
	//创建一个空层，并添加到当前场景中
	void createBlankLayerAndAddToThis(Layer*& layer, int order = 0);
	//暂停游戏
	void pause(Ref* sender);
};