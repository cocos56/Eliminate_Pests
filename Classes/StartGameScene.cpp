#include "StartGameScene.h"

QE_CreateSceneFromLayer_CPP(StartGameScene);
	//设置优先查找资源的目录
	paths = { "fonts", "StartGameScene" };
	QE_SetResourcesSearchDir;

	//添加背景
	QE_addBgSpriteToThis;

	//关闭菜单项
	MenuItem* closeItem = QMenu::createMenuItemSprite("CloseNormal.png", QE_CB0(StartGameScene, menuCloseCallback));
	closeItem->setPosition(winSize.width-closeItem->getContentSize().width, 0+closeItem->getContentSize().height);

	//创建开始游戏菜单精灵项
	MenuItem* startItem = QMenu::createMenuItemSprite("start.png", QE_CB0(StartGameScene, start));
	startItem->setPosition(Vec2(winSize.width/3-100, winSize.height/5));

	//创建游戏帮助菜单精灵项
	MenuItem* helpItem = QMenu::createMenuItemSprite("help.png", QE_CB0(StartGameScene,helpLayer));
	helpItem->setPosition(Vec2(winSize.width/3+400, winSize.height/5));

	Vector<MenuItem*> items = { closeItem, startItem , helpItem };
	QE_addMenuToThis;

	return true;
}
void StartGameScene::menuCloseCallback()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    // 程序执行结束,释放运行场景。
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void StartGameScene::helpLayer()
{
	QE_get_winSize;

	helpBg = Sprite::create("help_mianban.png");
	helpBg->setPosition(Vec2(winSize.width/2, winSize.height/2-100));
	addChild(helpBg);

	//ok按钮
	Menu* okButton = QMenu::createMenu("ok.png", QE_CB0(StartGameScene, helpBack));
	okButton->setPosition(Vec2(helpBg->getContentSize().width/2,80));
	helpBg->addChild(okButton);

	auto moveTo = MoveTo::create(0.3,Vec2(winSize.width/2, winSize.height/2));
	helpBg->runAction(moveTo);
}

void StartGameScene::helpBack()
{
	helpBg->removeFromParent();
}

void StartGameScene::start()
{
	//右边滑入剧场效果
	auto transition = TransitionSlideInR::create(0.3, SelectLevelScene::createScene());
	//push游戏场景
	Director::getInstance()->replaceScene(transition);
}