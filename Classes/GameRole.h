#pragma once

/*
EliminatePest所属的游戏场景下的游戏角色类下的游戏角色模块
含：
1.GameRole类
用途：用于给游戏中的角色提供支持，纯虚类，必须被其他类继承才能实例化对象。
*/

#include "QE.h"

class GameRole
{
public:
	/*本类有虚方法：updateObjGrouthAnimate、initGrouthAnimate
	、playDeathAnimate、initFightEffect、updateFightEffect
	因此是虚类，无法直接生成对象，可以让其它类继承它，然后生成其他类的对象。
	注意：其他类在继承时应重写所有虚方法。
	*/
	//剩余生长时间（至长到成熟）
	int _leftGrowingTime;
	//攻击力（点每秒）
	int _attack;
	//生命值（点）
	int _life = 6;
	//是否已死亡
	bool _isDied = false;
	//所在坐标
	Coordinate _c;

	/*所有动画帧与当前帧序号，然后利用QE封装好的方法就可以播放动画*/
	//所有成长动画帧
	vector<Sprite*> _growthFrames;
	//当前成长帧动画序号
	int _growthFrameNum = 1;
	//更新所有对象的生长动画帧
	void updateObjsGrouthAnimate() {};
	//更新当前对象的生长动画帧
	virtual void updateObjGrouthAnimate() = 0;
	//初始化生长动画
	virtual void initGrouthAnimate() = 0;
	//播放死亡动画
	virtual void playDeathAnimate() = 0;
	//所有战斗动画帧序号
	vector<Sprite*> _fightFrames;
	//当前战斗帧动画序号
	int _fightFrameNum = 1;
	//初始化战斗特效
	virtual void initFightEffect() = 0;
	//更新战斗特效
	virtual void updateFightEffect() = 0;
};