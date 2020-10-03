#include "SelectLevelScene.h"

vector<string> SelectLevelScene::_levelsName = { "winter", "spring", "autumn", "summer" };
string SelectLevelScene::_levelName = _levelsName.at(0);
int SelectLevelScene::_levelIndex = 1;
PageView* SelectLevelScene:: _pageView;

QE_CreateSceneFromLayer_CPP(SelectLevelScene);
	paths = { "SelectLevelScene" };
	QE_SetResourcesSearchDir;
	QE_addBgSpriteToThis;

	_levelIndex = UserDefault::getInstance()->getIntegerForKey("levelIndex", 1);

	initMenu();

	showSelect();

	initPageView();
    
    return true;
}

void SelectLevelScene::initMenu()
{
	//��ʼ�ؿ��˵���
	_start = QMenu::createMenuItemSprite("select.png", bind(SelectLevelScene::start));
	_start->setPosition(Vec2(winSize.width / 2 - 10, winSize.height * 0.15));
	//���ز˵���
	MenuItem* back = QMenu::createMenuItemSprite("back.png", QE_CB0(SelectLevelScene, back));
	back->setPosition(back->getContentSize().width / 2, winSize.height - back->getContentSize().height / 2 - 5);
	//����ѡ��ؿ��˵���
	_rightSelect = QMenu::createMenuItemSprite("rightSelect.png", [&](Object * sender) {_pageView->scrollToPage(SelectLevelScene::_levelIndex); });
	_rightSelect->setPosition(winSize.width - 210, winSize.height / 2 - 80);
	_rightSelect->setAnchorPoint(Vec2(1, 0));
	//����ѡ��ؿ��˵���
	_leftSelect = QMenu::createMenuItemSprite("rightSelect.png", [&](Object * sender) {_pageView->scrollToPage(SelectLevelScene::_levelIndex - 2); });
	_leftSelect->setScaleX(-1);
	_leftSelect->setPosition(190, winSize.height / 2 - 80);
	_leftSelect->setAnchorPoint(Vec2(1, 0));
	_playBgMusic = QMenu::createMenuItemSprite("playBgMusic.png", [&](Object * sender) { setPlayMusicStatus(true); });
	_playBgMusic->setPosition(winSize - Size(2, 5));
	_playBgMusic->setAnchorPoint(Vec2(1, 1));
	_playBgMusic->setScale(0.5);
	_stopBgMusic = QMenu::createMenuItemSprite("stopBgMusic.png", [&](Object * sender) { setPlayMusicStatus(false); });
	_stopBgMusic->setPosition(winSize - Size(2, 5));
	_stopBgMusic->setAnchorPoint(Vec2(1, 1));
	_stopBgMusic->setScale(0.5);
	//�Ѳ˵�����ӵ��˵���
	Vector<MenuItem*>items = { _start, back, _rightSelect, _leftSelect, _playBgMusic, _stopBgMusic };
	QE_addMenuToThis;
}

void SelectLevelScene::initPageView()
{
	//������ҳ������PageView
	_pageView = PageView::create();
	// ����PageView��ContentSize
	_pageView->setContentSize(Size(241.0f, 226.0f));
	// ����PageView����Ļ����λ��
	_pageView->setPosition(Vec2(winSize.width / 2 - 10, winSize.height / 2 - 20));
	_pageView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// ѭ����Ӹ�Layout���ؿ�ͼƬ��
	for (int i = 0; i < 4; i++)
	{
		// ����һ��Layout
		Layout* layout = Layout::create();
		layout->setContentSize(Size(241.0f, 226.0f));
		// ����һ��ImageView
		ImageView* imageView;
		if (isLevelLocked(i + 1))
		{
			imageView = ImageView::create(_levelsName.at(i) + "_locked.png");
		}
		else
		{
			imageView = ImageView::create(_levelsName.at(i) + ".png");
		}
		imageView->setContentSize(Size(241.0f, 226.0f));
		imageView->setPosition(Vec2(layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f));
		// ��ImageView���ΪLayout���ӽڵ�
		layout->addChild(imageView);
		// ��i��ʾ��λ���ϲ���Layout
		_pageView->insertPage(layout, i);
	}

	// ����¼�������
	_pageView->addEventListener(CC_CALLBACK_2(SelectLevelScene::pageViewCallBack, this));
	// ��PageView���δ������ӽڵ�
	addChild(_pageView);

	_pageView->scrollToPage(SelectLevelScene::_levelIndex - 1);
}

bool SelectLevelScene::isLevelLocked(int level)
{
	return level > UserDefault::getInstance()->getIntegerForKey("unlockedLevel", 1);
}

void SelectLevelScene::start()
{
	//��ʼ���ؿ���ɫ����
	CurrentLevelData::initGameLevelData(_levelName);

	// �ұ߻���糡Ч��
	auto transition = TransitionSlideInR::create(0.3, GameScene::createScene());
	// push��Ϸ����
	Director::getInstance()->replaceScene(transition);
};

void SelectLevelScene::back()
{
	// ��߻���糡Ч��
	auto transition = TransitionSlideInL::create(0.3, StartGameScene::createScene());
	Director::getInstance()->replaceScene(transition);
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();

};

void SelectLevelScene::showSelect()
{
	if (isLevelLocked(SelectLevelScene::_levelIndex))
	{
		_start->setEnabled(false);
	}
	else
	{
		_start->setEnabled(true);
	}
	if (SelectLevelScene::_levelIndex == 1)
	{
		_leftSelect->setVisible(false);
	}
	else if (SelectLevelScene::_levelIndex == 4)
	{
		_rightSelect->setVisible(false);
	}
	else
	{
		_leftSelect->setVisible(true);
		_rightSelect->setVisible(true);
	}
}

bool SelectLevelScene::isPlayBgMusic()
{
	bool status = UserDefault::getInstance()->getBoolForKey("isPlayBgMusic", true);
	_playBgMusic->setVisible(status);
	_stopBgMusic->setVisible(!status);
	return status;
}

void SelectLevelScene::setPlayMusicStatus(bool status)
{
	if (status)
	{
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
	else
	{
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}
	UserDefault::getInstance()->setBoolForKey("isPlayBgMusic", !status);
	_playBgMusic->setVisible(!status);
	_stopBgMusic->setVisible(status);
};

void SelectLevelScene::pageViewCallBack(Ref* pSender, PageView::EventType type)
{
	if (type == PageView::EventType::TURNING)
	{
		int curPage = _pageView->getCurPageIndex();
		_levelName = _levelsName.at(curPage);
		UserDefault::getInstance()->setIntegerForKey("levelIndex", curPage + 1);
		SelectLevelScene::_levelIndex = UserDefault::getInstance()->getIntegerForKey("levelIndex");
		SimpleAudioEngine::getInstance()->playBackgroundMusic((_levelName + ".mp3").c_str(), true);
		if (!isPlayBgMusic())
		{
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		}
		showSelect();
	}
}