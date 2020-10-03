#include "Pest.h"

//初始化类的静态成员变量
vector<Pest*>Pest::_objsList;

/*初始化构造函数*/
Pest::Pest()
{
	_attack = CurrentLevelData::_pestType.attack;
	name = CurrentLevelData::_pestType.name;
	_leftGrowingTime = 6;
	initGrouthAnimate();
	_objsList.push_back(this);
};
//初始化静态成员方法
void Pest::updateObjsGrouthAnimate()
{
	for (vector<Pest*>::iterator it = _objsList.begin(); it != _objsList.end(); it++)
	{
		(*it)->updateObjGrouthAnimate();
	}
}
//初始化成员方法
void Pest::updateObjGrouthAnimate()
{
	_leftGrowingTime--;
	if (_growthFrameNum >= _growthFrames.size()) { return; }

	_growthFrameNum++;
	QAnimate::playFramFromFrams(_growthFrames, _growthFrameNum);
}
void Pest::initGrouthAnimate()
{
	string dirName = "GameScene/pestTypes/";
	string fileName = name + "Growth";
	QAnimate::createFramsPlayerFromPlistFile(fileName, _growthFrames, _c.x - 55, _c.y - 20, GameScene::_pestLayer, dirName, 0.5);
}

void Pest::underAttackAction(vector<FightingVegetable*>& _fightingVegetables)
{
	for (vector<FightingVegetable*>::iterator it = _fightingVegetables.begin(); it != _fightingVegetables.end(); it++)
	{
		if ((*it)->_leftGrowingTime <= 0) { underAttackAction((*it)); }
		else
		{
			if (_growthFrames.size() == 0) { initGrouthAnimate(); }
			else { updateObjGrouthAnimate(); }
			return;
		}
	}
}

void Pest::underAttackAction(FightingVegetable* _fightingVegetable)
{
	if (_isDied) { return; }
	if (_life <= 0)
	{
		_isDied = true;
		playDeathAnimate();
	}
	else{ _life -= _fightingVegetable->_attack; }
}
void Pest::playDeathAnimate()
{
	string dirName = "GameScene/pestTypes/";
	string fileName = name + "Death";
	Animate* animate;
	Sprite* s;
	QAnimate::initAnimateFromPlistFile(animate, s, _c.x - 55, _c.y - 20, fileName, dirName, 0.35);
	GameScene::_pestLayer->addChild(s);
	s->runAction(animate);
}
void Pest::initFightEffect()
{
	string dirName = "GameScene/pestTypes/";
	string fileName = name + "Movement";
	QAnimate::createFramsPlayerFromPlistFile(fileName, _fightFrames, _c.x - 55, _c.y - 20, GameScene::_pestLayer, dirName, 0.5);
}
void Pest::updateFightEffect()
{
	if (_growthFrameNum >= _growthFrames.size()) { _fightFrameNum = 0; }
	_fightFrameNum++;
	QAnimate::playFramFromFrams(_fightFrames, _fightFrameNum);
}
