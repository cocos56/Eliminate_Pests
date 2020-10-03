#include "LoadingScene.h"

QE_CreateSceneFromLayer_CPP(LoadingScene);
	paths = { "fonts" , "LoadingScene" };
	QE_SetResourcesSearchDir;

	//背景
	QE_addBgSpriteToThis;

	auto label = Label::createWithTTF("Load...","Marker Felt.ttf",30);
	label->setColor(Color3B::RED);
	label->setPosition(Vec2(winSize.width/2, winSize.height/2+50));
	this->addChild(label);

	//进度条
	auto timerSp = Sprite::create("loading.png");
	auto timer = ProgressTimer::create(timerSp);
	timer->setPosition(Vec2(winSize.width/2, winSize.height/2));
	//timer->setBarChangeRate(Vec2(1,0));
	timer->setType(ProgressTimer::Type::BAR);//类型
	timer->setMidpoint(Vec2(0,0.5));//基准点
	timer->setPercentage(0);//开始位置
	this->addChild(timer);

	auto progressTo = ProgressTo::create(0.7, 100);
	auto call = CallFunc::create(CC_CALLBACK_0(LoadingScene::startScene,this));
	auto sequence = Sequence::create(progressTo,call,NULL);
	timer->runAction(sequence);
	return true;
}
void LoadingScene::startScene()
{
	auto start = StartGameScene::createScene();
	//翻页
	auto turn = TransitionPageTurn::create(1,start,false);
	Director::getInstance()->replaceScene(turn);
}