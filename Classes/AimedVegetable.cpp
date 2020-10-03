#include "AimedVegetable.h"

//初始化类的静态成员变量
int AimedVegetable::_ripeNum = 0;
vector< AimedVegetable*> AimedVegetable::_unripeList;
vector<AimedVegetable*>AimedVegetable::_objsList;

/*初始化构造函数*/
AimedVegetable::AimedVegetable()
{
	_leftGrowingTime = CurrentLevelData::_aimedVegetableType.maturingAge;
	//初始化坐标
	_c = GameScene::_plantC;
	//设置种植界面不可见，相应土地块上的种植按钮也不可见
	GameScene::showPlantItems();
	GameScene::_plantItems.at(_c.num)->setVisible(false);

	initGrouthAnimate();
	//playDeathAnimate();

	_objsList.push_back(this);

	FightingVegetable::isProtecting(this);

	//构造时把自己加入未成熟的目标植物列表
	_unripeList.push_back(this);
};
//初始化静态成员方法
void AimedVegetable::addRipeNumFromUnripeList()
{
	for (vector<AimedVegetable*>::iterator it = _unripeList.begin(); it != _unripeList.end();)
	{
		if ((*it)->_leftGrowingTime == 0) {
			_ripeNum++;
			it = _unripeList.erase(it);
		}
		else { it++; }
	}
}
void AimedVegetable::updateObjsGrouthAnimate()
{
	for (vector<AimedVegetable*>::iterator it = _objsList.begin(); it != _objsList.end(); it++)
	{
		(*it)->updateObjGrouthAnimate();
	}
}
void AimedVegetable::updateObjsStatus()
{
	for (vector<AimedVegetable*>::iterator it = _objsList.begin(); it != _objsList.end(); it++)
	{
		(*it)->updateObjStatus();
	}
}

//初始化成员方法
void AimedVegetable::updateObjStatus()
{
	//未成熟时暂不考虑生虫的情况
	if (_leftGrowingTime > 0) { return; }
	//成熟了，但受到保护
	if (isUnderProtecting()) 
	{
		if (!_isAddToRipeNum)
		{
			_ripeNum ++;
			_isAddToRipeNum = true;
		}
		
		if (_pest)
		{
			_pest->underAttackAction(_fightingVegetables);
			return;
		}
		return; 
	}
	//成熟了，未受到保护
	if (_pest)
	{
		if (_pest->_leftGrowingTime > 0)
		{
			underAttackAction();
			_pest->updateObjGrouthAnimate();
			return;
		}
		if (_pest->_fightFrames.size() == 0) { _pest->initFightEffect(); }
		else { _pest->updateFightEffect(); }
	}
	else{ getPest(); }
}

void AimedVegetable::underAttackAction()
{
	if (_pest->_fightFrames.size() == 0) { _pest->initFightEffect(); }
	else { _pest->updateFightEffect(); }

	if (_isDied) { return; }
	if (_life <= 0)
	{
		_isDied = true;
		playDeathAnimate();
	}
	else { _life -= _pest->_attack; }
}

bool AimedVegetable::isUnderProtecting()
{
	for (vector<FightingVegetable*>::iterator it = _fightingVegetables.begin(); it != _fightingVegetables.end(); it++)
	{
		if ((*it)->_leftGrowingTime<=0)
		{
			return true;
		}
	}
	return false;
}


void AimedVegetable::updateObjGrouthAnimate()
{
	if (_leftGrowingTime > 0) { _leftGrowingTime--; };
	if (_growthFrameNum >= _growthFrames.size()) { return; }

	_growthFrameNum++;
	QAnimate::playFramFromFrams(_growthFrames, _growthFrameNum);
}
void AimedVegetable::initGrouthAnimate()
{
	string dirName = "GameScene/aimedVegetableTypes/";
	string fileName = CurrentLevelData::_aimedVegetableType.name + "Growth";
	QAnimate::createFramsPlayerFromPlistFile(fileName, _growthFrames, _c.x - 55, _c.y - 20, GameScene::_vegetableLayer, dirName);
}
void AimedVegetable::playDeathAnimate()
{
	QAnimate::playFramFromFrams(_growthFrames, -1);
	string dirName = "GameScene/aimedVegetableTypes/";
	string fileName = CurrentLevelData::_aimedVegetableType.name + "Death";
	Animate* animate;
	Sprite* s;
	QAnimate::initAnimateFromPlistFile(animate, s, _c.x - 55, _c.y - 20, fileName, dirName, 1.0, false);
	GameScene::_vegetableLayer->addChild(s);
	s->runAction(animate);
}
void AimedVegetable::getPest()
{
	if (_pest) { return; }
	int r = cocos2d::random(0, RAND_MAX) % CurrentLevelData::_pestTypes.size();
	//int r = random() % CurrentLevelData::_pestTypes.size();
	CurrentLevelData::_pestType = CurrentLevelData::_pestTypes[r];
	_pest = new Pest;
	_pest->_c = _c;
	_pest->_c.x += 40;
	_pest->_c.y += 5;
}

