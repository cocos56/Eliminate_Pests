#pragma once

/*
EliminatePest��������Ϸ�����µĲ��µ��߲�ģ��
����
1.Vegetable��
��;�����ڹ�������ֲ�߲˰�ť��Ĳ���
*/

#include "QE.h"

class Vegetable
{
public:
	static int order;
	static void plantAimedVegetables();
	static void plantFightingVegetables(const string name);
};