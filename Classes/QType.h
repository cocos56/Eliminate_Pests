#pragma once

/*
Quick Engine����������������ģ��
����
1.Coordinate��
��;�����ڹ�������
*/


class Coordinate
{
public:
	Coordinate(int num, int x, int y) : num(num), x(x), y(y) {};
	Coordinate(int x, int y) : num(0), x(x), y(y) {};
	Coordinate() : num(-1), x(-1), y(-1) {};

	int num, x, y;
};

#include "QE.h"