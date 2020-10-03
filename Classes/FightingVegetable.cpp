#include "FightingVegetable.h"

//��ʼ����ľ�̬��Ա����
vector<FightingVegetable*>FightingVegetable::_objsList;

/*��ʼ�����캯��*/
FightingVegetable::FightingVegetable()
{
	_attack = CurrentLevelData::_fightingVegetableType.attack;
	_leftGrowingTime = 10;

	//��ʼ������
	_c = GameScene::_plantC;
	//������ֲ���治�ɼ�����Ӧ���ؿ��ϵ���ֲ��ťҲ���ɼ�
	GameScene::showPlantItems();
	GameScene::_plantItems.at(_c.num)->setVisible(false);

	initFightEffect();
	initGrouthAnimate();

	isProtecting(this);
	_objsList.push_back(this);
}
//��ʼ����̬��Ա����
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
//��ʼ����Ա����
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
	//���������Ч
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