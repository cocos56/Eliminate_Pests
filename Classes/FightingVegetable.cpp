#include "FightingVegetable.h"

//初始化类的静态成员变量
vector<FightingVegetable*>FightingVegetable::_objsList;

/*初始化构造函数*/
FightingVegetable::FightingVegetable()
{
	_attack = CurrentLevelData::_fightingVegetableType.attack;
	_leftGrowingTime = 10;

	//初始化坐标
	_c = GameScene::_plantC;
	//设置种植界面不可见，相应土地块上的种植按钮也不可见
	GameScene::showPlantItems();
	GameScene::_plantItems.at(_c.num)->setVisible(false);

	initFightEffect();
	initGrouthAnimate();

	isProtecting(this);
	_objsList.push_back(this);
}
//初始化静态成员方法
bool FightingVegetable::isProtecting(Coordinate a, Coordinate b)
{
	int ab = abs(a.num - b.num);
	bool special = !((a.num % 4 == 0 && b.num % 4 == 3) || (a.num % 4 == 3 && b.num % 4 == 0));
	return (ab == 1 || ab == 3 || ab == 4 || ab == 5) && special;
}
void FightingVegetable::isProtecting(AimedVegetable * target)
{
	for (vector<FightingVegetable*>::iterator it = _objsList.begin(); it != _objsList.end(); it++)
	{
		if (isProtecting((*it)->_c, target->_c))
		{
			target->_fightingVegetables.push_back((*it));
		}
	}
}
void FightingVegetable::isProtecting(FightingVegetable * target)
{
	for (vector<AimedVegetable*>::iterator it = AimedVegetable::_objsList.begin(); it != AimedVegetable::_objsList.end(); it++)
	{
		if (isProtecting((*it)->_c, target->_c))
		{
			(*it)->_fightingVegetables.push_back(target);
		}
	}
}
void FightingVegetable::updateObjsGrouthAnimate()
{
	for (vector<FightingVegetable*>::iterator it = _objsList.begin(); it != _objsList.end(); it++)
	{
		(*it)->updateObjGrouthAnimate();
	}
}
void FightingVegetable::updateObjsFightEffect()
{
	for (vector<FightingVegetable*>::iterator it = _objsList.begin(); it != _objsList.end(); it++)
	{
		(*it)->updateFightEffect();
	}
}
//初始化成员方法
void FightingVegetable::updateObjGrouthAnimate()
{
	if (_leftGrowingTime > 0) { _leftGrowingTime--; };
	if (_growthFrameNum >= _growthFrames.size()) { return; }

	_growthFrameNum++;
	QAnimate::playFramFromFrams(_growthFrames, _growthFrameNum);
}
void FightingVegetable::initGrouthAnimate()
{
	string dirName = "GameScene/fightingVegetableTypes/";
	string fileName = CurrentLevelData::_fightingVegetableType.name;
	QAnimate::createFramsPlayerFromPlistFile(fileName, _growthFrames, _c.x - 81, _c.y - 30, GameScene::_pestLayer, dirName);
}
void FightingVegetable::initFightEffect()
{
	//添加粒子特效
	fightEffectPlayer = ParticleSystemQuad::create("FightingEffect.plist");
	fightEffectPlayer->setPosition(_c.x, _c.y + 20);
	fightEffectPlayer->setVisible(false);
	fightEffectPlayer->setScale(0.5);
	GameScene::_particleLayer->addChild(fightEffectPlayer);
}
void FightingVegetable::updateFightEffect()
{
	if (_leftGrowingTime <= 0)
	{
		fightEffectPlayer->setVisible(true);
		fightEffectPlayer->resetSystem();
	}
}