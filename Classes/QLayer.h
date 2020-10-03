#pragma once

/*
Quick Engine�������ٲ�ģ��
��;�����ڿ��ٴ���Layer�����࣬��������Ӧ�ĳ�ʼ����
*/

#define QE_CreateLayerFromLayer_H(TYPE) \
public: \
	CREATE_FUNC(TYPE); \
	virtual bool init(); \
	QE_get_winSize;

#define QE_CreateLayerFromLayer_CPP(TYPE) \
bool TYPE::init() \
{ \
	if (!Layer::init()) \
	{ \
		return false; \
	}
