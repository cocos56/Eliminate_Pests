#include "TimeLayer.h"

QE_CreateLayerFromLayer_CPP(TimeLayer);
	//初始化好一个Lable并把里面的字体进行好转换,用来显示时间
	_countTimeLabel = getLabel(50);

	Sprite* clock = Sprite::create("clock.png");
	clock->setAnchorPoint(Vec2(0, 0));
	clock->setPosition(0, winSize.height - _countTimeLabel->getContentSize().height-30);
	addChild(clock);

	Sprite* aimedVegetableSprite = Sprite::create(CurrentLevelData::_aimedVegetableType.name + ".png");
	aimedVegetableSprite->setAnchorPoint(Vec2(0, 0));
	aimedVegetableSprite->setPosition(150, winSize.height - _countTimeLabel->getContentSize().height - 18);
	addChild(aimedVegetableSprite);

	_aimedVegetableLabel = getLabel(150 + 10 + aimedVegetableSprite->getContentSize().width);

	this->schedule(schedule_selector(TimeLayer::myUpdate), 1);

	return true;
}

void TimeLayer::myUpdate(float f)
{
	CurrentLevelData::_time -= 1;
	if (CurrentLevelData::_time > 0)
	{
		//更新时间和当前收获的植株量的标签
		updateLabel();
		//更新战斗蔬菜的动画特效
		FightingVegetable::updateObjsFightEffect();
		//更新所有对象的生长动画
		FightingVegetable::updateObjsGrouthAnimate();
		AimedVegetable::updateObjsGrouthAnimate();
		//更新所有对象的战斗特效
		FightingVegetable::updateObjsFightEffect();
		//更新所有目标植株自身以及在它上面的虫子的状态
		AimedVegetable::updateObjsStatus();
	}
	else
	{
		unschedule(schedule_selector(TimeLayer::myUpdate));
		GameScene::_pause_item->setVisible(false);
		QScene::saveNowSceneToFile();

		if (AimedVegetable::_ripeNum >= CurrentLevelData::_winNum) { win(); }
		else { fail(); }
	}
}

void TimeLayer::win()
{
	auto action = [](float dt)
	{
		Scene* scene = PauseScene::createWinScene();
		Director::getInstance()->pushScene(scene);
	};
	auto schedules = getScheduler();//获取调度对象
	schedules->schedule(action, this, 0.0f, 0, 0.8f, false, "win_screen");
}

void TimeLayer::fail()
{
	auto action = [](float dt)
	{
		Scene* scene = PauseScene::createFailScene();
		Director::getInstance()->pushScene(scene);
	};
	auto schedules = getScheduler();//获取调度对象
	schedules->schedule(action, this, 0.0f, 0, 0.8f, false, "fail_screen");
}

LabelTTF* TimeLayer::getLabel(int x)
{
	LabelTTF* label = LabelTTF::create("   ", "Marker Felt.ttf", 30);
	label->setPosition(x, winSize.height - 43);
	label->setAnchorPoint(Vec2(0, 0));
	label->setColor(Color3B(0, 0, 0));
	addChild(label);
	return label;
}

void TimeLayer::updateLabel()
{
	_countTimeLabel->setString(to_string(CurrentLevelData::_time));
	_aimedVegetableLabel->setString(to_string(AimedVegetable::_ripeNum));
}