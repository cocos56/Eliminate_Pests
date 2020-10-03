#include "PauseScene.h"

Layer* PauseScene:: _layer;
Size PauseScene::winSize = QE_winSize;

Scene* PauseScene::createScene()
{
	Scene* scene = Scene::create();
	_layer = Layer::create();
	scene->addChild(_layer);
	return scene;
}

Scene* PauseScene::createFailScene()
{
	Scene* scene = createScene();
	addBg();
	Sprite* defeat = Sprite::create("defeat.png");
	defeat->setPosition(winSize/2);
	defeat->setAnchorPoint(Vec2(0.5, 0.5));
	_layer->addChild(defeat);

	Vector<MenuItem*> items;
	MenuItem* item;
	//返回菜单项
	item = QMenu::createMenuItemSprite("back.png", bind(back));
	item->setPosition(winSize.width / 2 - 120, 200);
	items.pushBack(item);
	//重新开始菜单项
	item = QMenu::createMenuItemSprite("restart.png", bind(SelectLevelScene::start));
	item->setPosition(winSize.width / 2 + 120, 200);
	items.pushBack(item);

	QE_addMenuTo(_layer);
	return scene;
}

Scene* PauseScene::createWinScene()
{
	//解锁关卡数+1
	UserDefault::getInstance()->setIntegerForKey("unlockedLevel", SelectLevelScene::_levelIndex + 1);

	Scene* scene = createScene();
	addBg();
	Sprite* win;

	Vector<MenuItem*> items;
	MenuItem* item;
	//返回菜单项
	item = QMenu::createMenuItemSprite("back.png", bind(back));
	item->setPosition(winSize.width / 2 - 120, 200);
	items.pushBack(item);
	//重新开始菜单项
	item = QMenu::createMenuItemSprite("restart.png", bind(SelectLevelScene::start));
	item->setPosition(winSize.width / 2, 200);
	items.pushBack(item);

	if (SelectLevelScene::_levelIndex >= 4) { win = Sprite::create("finallyWin.png"); }
	else
	{
		//下一关菜单项
		item = QMenu::createMenuItemSprite("next.png", bind(SelectLevelScene::start));
		item->setPosition(winSize.width / 2 + 120, 200);
		items.pushBack(item);
		win = Sprite::create("win.png"); 
	}
	
	win->setPosition(0, 0);
	win->setAnchorPoint(Vec2(0, 0));
	_layer->addChild(win);

	QE_addMenuTo(_layer);

	return scene;
}

Scene* PauseScene::createPauseScene()
{
	Scene* scene = createScene();
	addBg();
	MenuItem* resumeItem = QMenu::createMenuItemSprite("resume.png", bind(&resume, placeholders::_1));
	Size contentSize = resumeItem->getContentSize();
	resumeItem->setPosition(winSize.width - contentSize.width -10, winSize.height - contentSize.height -10);
	resumeItem->setAnchorPoint(Vec2(0, 0));
	MenuItem * backItem = QMenu::createMenuItemSprite("back.png", bind(back));
	backItem->setPosition(winSize/2);
	backItem->setAnchorPoint(Vec2(0, 0));

	Vector<MenuItem*> items = { resumeItem, backItem };

	QE_addMenuTo(_layer);

	return scene;
}

void PauseScene::addBg()
{
	string bg_name = FileUtils::getInstance()->getWritablePath() + "pause.png";
	//字符串格式的可读些路径
	Sprite* bg = Sprite::create(bg_name);
	bg->setPosition(0, 0);
	bg->setAnchorPoint(Vec2(0, 0));
	_layer->addChild(bg);
}

void PauseScene::resume(Ref* sender)
{
	GameScene::_pause_item->setVisible(true);
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	Director::getInstance()->popScene();
}

void PauseScene::back()
{
	// 左边滑入剧场效果
	auto transition = TransitionSlideInL::create(0.3, SelectLevelScene::createScene());
	Director::getInstance()->replaceScene(transition);
}