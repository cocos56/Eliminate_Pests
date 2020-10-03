#include "QTMX.h"

void QTMX::initCoordinatesByTMXFile(vector<Coordinate>& coordinates, const string& fileName, const string& objectGroupName)
{
	coordinates.clear();
	TMXTiledMap* tiledMap = TMXTiledMap::create(fileName);
	TMXObjectGroup* objGroup = tiledMap->getObjectGroup(objectGroupName);
	ValueVector values = objGroup->getObjects();
	for (size_t i = 0, length = values.size(); i < length; i++)
	{
		ValueMap value = values.at(i).asValueMap();
		int x = value.at("x").asInt();
		int y = value.at("y").asInt();
		coordinates.push_back(Coordinate(i, x, y));
	}
}

void QTMX::initCoordinatesByTMXFile(Coordinate& coordinate, const string& fileName, const string& objectGroupName)
{
	TMXTiledMap* tiledMap = TMXTiledMap::create(fileName);
	TMXObjectGroup* objGroup = tiledMap->getObjectGroup(objectGroupName);
	ValueVector values = objGroup->getObjects();

	//�жϽ����Ķ�����Ƿ��ж����������У�����ô˽ӿڵĿ�����Ա��������
	CCASSERT(values.size() == 1, "values.size not = 1");
	ValueMap value = values.at(0).asValueMap();
	int x = value.at("x").asInt();
	int y = value.at("y").asInt();
	coordinate = Coordinate(x, y);
}