#pragma once

/*
Quick Engine���������ļ�ʹ��ģ��
��;�����ڿ���������Դ����·��
*/

#include "QE.h"

#define QE_SetResourcesSearchDir \
CCASSERT(paths.size(), "paths.size should not = 0"); \
FileUtils::getInstance()->setSearchResolutionsOrder(paths);