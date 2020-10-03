#include "QJson.h"

QE_SINGLETON_CPP(QJson);

JDoc QJson::getDocFromJsonFile()
{
	//��ȡJson�ļ����ڵ�·��
	string  filefullPath = FileUtils::getInstance()->fullPathForFilename("Data.json");
	CCLOG("fullPath=%s", filefullPath.c_str());//����filefullPath��ȫ·������D:/projects/SnailGoHome/Resources/Data.json��
	Data data = FileUtils::getInstance()->getDataFromFile(filefullPath);
	//��Data����content
	string content = string((const char*)data.getBytes(), 0, data.getSize());

	//��content����document
	JDoc document;
	document.Parse<0>(content.c_str());

	//��������
	CCASSERT(!document.HasParseError(), "Parsing to document failure.");
	CCLOG("Parsed to document successfully !");

	//�ж��Ƿ��Ƕ���
	CC_ASSERT(document.IsObject());

	return document;
}

JValue& QJson::getArray(string key, JValue& value)
{
	//ȷ��ӵ����Ӧ��ֵ
	CC_ASSERT(value.HasMember(key.c_str()));
	JValue& v1 = value[key.c_str()];

	//ȷ���������ֵ��Array���͵�
	CC_ASSERT(v1.IsArray());
	return v1;
}

int QJson::getInt(string key, JValue& value)
{
	//ȷ��ӵ����Ӧ��ֵ
	CC_ASSERT(value.HasMember(key.c_str()));
	JValue& v1 = value[key.c_str()];

	//ȷ���������ֵ��Int���͵�
	CC_ASSERT(v1.IsInt());
	int v2 = v1.GetInt();

	//�ͷ���ʱ������ռ�õĿռ�
	v1.~GenericValue();
	
	//����������Ҫ��ֵ
	return v2;
}

string QJson::getString(string key, JValue& value)
{
	//ȷ��ӵ����Ӧ��ֵ
	CC_ASSERT(value.HasMember(key.c_str()));
	JValue& v1 = value[key.c_str()];

	//ȷ���������ֵ��String���͵�
	CC_ASSERT(v1.IsString());
	string v2 = v1.GetString();

	//�ͷ���ʱ������ռ�õĿռ�
	v1.~GenericValue();

	//����������Ҫ��ֵ
	return v2;
}