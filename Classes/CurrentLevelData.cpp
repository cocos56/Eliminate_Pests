#include "CurrentLevelData.h"

QE_SINGLETON_CPP(CurrentLevelData);

//��ʼ����̬����
JDoc CurrentLevelData::document;
int CurrentLevelData::_time = 0;
int CurrentLevelData::_winNum = 0;
PestType CurrentLevelData::_pestType;
FightingVegetableType CurrentLevelData::_fightingVegetableType;
AimedVegetableType CurrentLevelData::_aimedVegetableType;
vector<PestType> CurrentLevelData::_pestTypes;
vector<FightingVegetableType> CurrentLevelData::_fightingVegetableTypes;

void CurrentLevelData::initFightingVegetableType(const string name)
{
	for (size_t i = 0, length = _fightingVegetableTypes.size(); i < length; i++)
	{
		if (_fightingVegetableTypes.at(i).name == name)
		{
			_fightingVegetableType = _fightingVegetableTypes.at(i);
			return;
		}
	}
}

void CurrentLevelData::initGameLevelData(string levelName)
{
	document = QJson::getDocFromJsonFile();
	//��ȡ�ؿ�����
	JValue& level = document[levelName.c_str()]; //��ȡ���ĵ�����
	getInstance()->getLevelValue(level);
}
void CurrentLevelData::getLevelValue(JValue& level)
{
	_time = QJson::getInt("countdown", level);
	_winNum = QJson::getInt("aimedVegetables", level);

	JValue& aimedVegetableType = level["aimedVegetableType"];
	initAimedVegetableType(aimedVegetableType);

	JValue& pestTypes = QJson::getArray("pestTypes", level);
	initPestTypes(pestTypes);

	JValue& fightingVegetableTypes = QJson::getArray("fightingVegetableTypes", level);
	initFightingVegetableTypes(fightingVegetableTypes);

	//����level�����ͷ�����ռ�õ��ڴ�
	level.~GenericValue();
}
void CurrentLevelData::initAimedVegetableType(JValue& aimedVegetableType)
{
	_aimedVegetableType.name = QJson::getString("name", aimedVegetableType);
	_aimedVegetableType.hp = QJson::getInt("hp", aimedVegetableType);
	_aimedVegetableType.maturingAge = QJson::getInt("maturingAge", aimedVegetableType);
	_aimedVegetableType.pestAppearingTime = QJson::getInt("pestAppearingTime", aimedVegetableType);
	//�����˾�����
	aimedVegetableType.~GenericValue();
}
void CurrentLevelData::initPestTypes(JValue& pestTypes)
{
	_pestTypes.clear();
	for (size_t i = 0, length = pestTypes.Size(); i < length; i++)
	{
		PestType t;
		JValue& pestType = pestTypes[i];
		t.name = QJson::getString("name", pestType);
		t.hp = QJson::getInt("hp", pestType);
		t.attack = QJson::getInt("attack", pestType);
		t.maturingAge = QJson::getInt("maturingAge", pestType);
		_pestTypes.push_back(t);

		//����������һ�£��ͷſռ�
		pestType.~GenericValue();
	}
	//����������һ�£��ͷſռ�
	pestTypes.~GenericValue();
}
void CurrentLevelData::initFightingVegetableTypes(JValue& fightingVegetableTypes)
{
	_fightingVegetableTypes.clear();
	for (size_t i = 0, length = fightingVegetableTypes.Size(); i < length; i++)
	{
		FightingVegetableType t;
		JValue& fightingVegetableType = fightingVegetableTypes[i];
		t.name = QJson::getString("name", fightingVegetableType);
		t.attack = QJson::getInt("attack", fightingVegetableType);
		t.maturingAge = QJson::getInt("maturingAge", fightingVegetableType);
		_fightingVegetableTypes.push_back(t);

		//����������һ�£��ͷſռ�
		fightingVegetableType.~GenericValue();
	}
	//����������һ�£��ͷſռ�
	fightingVegetableTypes.~GenericValue();
}