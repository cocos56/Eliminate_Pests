#pragma once

/*
Quick Engine��������Json��дģ��
����
1.QJson��
��;�����ڿ��ٶ�дJson�ļ�
*/

#include "json/document.h"
#include "json/reader.h"
//#include "json/writer.h"
#include  "json/stringbuffer.h"
typedef rapidjson::Value JValue;
typedef rapidjson::Document JDoc;

#include "QE.h"

class QJson
{
	QE_SINGLETON_H(QJson);
public:
	static JDoc getDocFromJsonFile();

	//get the array of key from value
	static JValue& getArray(string key, JValue& value);
	static int getInt(string key, JValue& value);
	static string getString(string key, JValue& value);
};