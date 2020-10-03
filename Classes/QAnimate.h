#pragma once

/*
Quick Engine�������ٶ���ģ��
����
1.QAnimate��
��;�����ڿ��ٴ�������
*/

#include "QE.h"

class QAnimate
{
public:
	static void createFramsPlayerFromPlistFile(const string& fileName, vector<Sprite*> &sprites, int x, int y, Layer* layer, string dirName = "", float scale = 1.0f);
	//�����ж���֡�в���ĳһ֡��num����Ҫ���ŵ�֡��ţ�Ĭ�������numΪ1�������������num<=0�������������֡����ֹͣ�������ţ������������num>=frames.size()�������ʾ���һ֡
	static void playFramFromFrams(vector<Sprite*> &frames, int num = 1);
	static void initAnimateFromPlistFile(Animate*& animate, Sprite*& sprite, int x, int y, const string& fileName, string dirName = "", float scale = 1.0f, bool isRestoreOriginalFrame =true);
private:
	//ͨ��plist�ļ�����������ǰ�Ķ����ж��ٸ�����֡��ͨ��plist�ļ�ֻ�ǽ�������һ�����֣���������ǵ�ǰ������֡���������֡�������ڱ���ľ�̬��Աnum��
	static void initFramsNumFromPlistFile(const string& fileName);
	static int num;
};