#pragma once

/*
Quick Engine�������ٶ���ģ��
����
1.QObject��
��;�����ڿ��ٹ������
*/


#include "QE.h"

class QObject
{
public:
	template<class T>
	static void releaseVector(vector<T*>& vec)
	{
		for (size_t i = 0, length = vec.size(); i < length; i++)
		{
			delete vec.at(i);
		}
		vec.clear();
	}
};