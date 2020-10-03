#pragma once

/*
EliminatePest��������Ϸ�����µĵ�ǰ�ؿ�����ģ��
����
1.PestType��
��;�����ɵĶ�������ڼ�¼��ͬ�������͵�����
2.AimedVegetableType��
��;�����ɵĶ�������ڼ�¼��ͬĿ���߲����͵�����
3.FightingVegetableType��
��;�����ɵĶ�������ڼ�¼��ͬս���߲����͵�����
4.CurrentLevelData��
��;�����ڹ���ǰ�ؿ�������
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
	//��������
	//timeΪ����ͨ�ص���ʱ��winNumΪ����ʤ����Ҫ�ɹ��ջ�������
	static int _time, _winNum;
	static vector<PestType> _pestTypes;
	static PestType _pestType;
	static vector<FightingVegetableType> _fightingVegetableTypes;
	static FightingVegetableType _fightingVegetableType;
	static void initFightingVegetableType(const string name);
	static AimedVegetableType _aimedVegetableType;

public:
	//JSON�ļ�����
	static void initGameLevelData(string levelName);
	void getLevelValue(JValue& level);
	void initAimedVegetableType(JValue& aimedVegetableType);
	void initPestTypes(JValue& pestTypes);
	void initFightingVegetableTypes(JValue& fightingVegetableTypes);
public:
	static JDoc document;
};
