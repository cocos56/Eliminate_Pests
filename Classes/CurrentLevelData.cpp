#include "CurrentLevelData.h"

QE_SINGLETON_CPP(CurrentLevelData);

//初始化静态变量
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
	//读取关卡数据
	JValue& level = document[levelName.c_str()]; //读取中文的数组
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

	//析构level对象，释放其所占用的内存
	level.~GenericValue();
}
void CurrentLevelData::initAimedVegetableType(JValue& aimedVegetableType)
{
	_aimedVegetableType.name = QJson::getString("name", aimedVegetableType);
	_aimedVegetableType.hp = QJson::getInt("hp", aimedVegetableType);
	_aimedVegetableType.maturingAge = QJson::getInt("maturingAge", aimedVegetableType);
	_aimedVegetableType.pestAppearingTime = QJson::getInt("pestAppearingTime", aimedVegetableType);
	//用完了就析构
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

		//用完了析构一下，释放空间
		pestType.~GenericValue();
	}
	//用完了析构一下，释放空间
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

		//用完了析构一下，释放空间
		fightingVegetableType.~GenericValue();
	}
	//用完了析构一下，释放空间
	fightingVegetableTypes.~GenericValue();
}