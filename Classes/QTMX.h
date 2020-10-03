#pragma once

/*
Quick Engine��������TMXģ��
����
1.QTMX��
��;�����ڿ��ٹ���TMX�ļ�����Ҫ���ڴ�TMX�ļ��н�������
*/

#include "QE.h"

class QTMX
{
public:
	static void initCoordinatesByTMXFile(vector<Coordinate>& coordinates,const string& fileName, const string& objectGroupName);
	static void initCoordinatesByTMXFile(Coordinate& coordinate, const string& fileName, const string& objectGroupName);
};

