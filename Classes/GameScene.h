#pragma once

/*
EliminatePest��������Ϸ�����µ���Ϸ����ģ��
����
1.GameScene��
��;�����ڹ�����Ϸ����
*/

#include "QE.h"

class GameScene :public Layer
{
QE_CreateSceneFromLayer_H(GameScene);
public:
	static void plant(Coordinate c);
	static void showPlantItems(bool isShow = false);

public:
	static Coordinate _plantC;
	vector<Coordinate> _coordinates;
	static vector<MenuItem*> _plantItems;
	static Layer* _vegetableLayer, * _pestLayer, * _particleLayer, *_plantLayer, *_timeLayer;
	//��ͣ��Ϸ����˵���
	static MenuItem* _pause_item;

	//���³�ʼ�����������ڰ��˷����ٽ�����Ϸ����Ҫ��֮ǰ��һЩ�Զ�������������Լ����³�ʼ��
	void reinitVar();
	//�Ƿ���Ҫ���³�ʼ����������Ϸ���һ�ν�����Ϸ��������Ҫ�����ص����������ٴν�����Ϸ����ʱ��Ҫ��
	static bool _shouldReinitVar;
	//��ʼ����ֲ�˵��������
	void initCoordinates();
	//��ʼ�����в˵���
	void initMenuItems();
	//��ʼ����ֲֲ��Ĳ˵����
	void initPlantItems();
	//��ʼ�����в�
	void initLayers();
	//����һ���ղ㣬����ӵ���ǰ������
	void createBlankLayerAndAddToThis(Layer*& layer, int order = 0);
	//��ͣ��Ϸ
	void pause(Ref* sender);
};