#include "GameScene.h"

bool GameScene::_shouldReinitVar = false;
Coordinate GameScene::_plantC;
vector<MenuItem*> GameScene::_plantItems;
Layer* GameScene::_vegetableLayer;
Layer* GameScene::_pestLayer;
Layer* GameScene::_particleLayer;
Layer* GameScene::_plantLayer;
Layer* GameScene::_timeLayer;
MenuItem* GameScene::_pause_item;

QE_CreateSceneFromLayer_CPP(GameScene)
	//设置查找资源的目录
	paths = { "fonts", "GameScene",
	"GameScene/aimedVegetableTypes", "GameScene/fightingVegetableTypes",
	"GameScene/pestTypes", "GameScene/plantLayer",
	"GameScene/timeLayer"
	};
	QE_SetResourcesSearchDir;

	//添加背景
	addChild(QSprite::createBgSprite(SelectLevelScene::_levelName + ".png"));

	if (_shouldReinitVar) { reinitVar(); };

	initCoordinates();
	initLayers();
	initMenuItems();

	_shouldReinitVar = true;

	return true;
}

void GameScene::reinitVar()
{

	AimedVegetable::_ripeNum = 0;

	SpriteFrameCache::getInstance()->removeSpriteFrames();
	//
	QMenu::releaseMenuItemVector(_plantItems);

	//
	QObject::releaseVector(AimedVegetable::_objsList);
	QObject::releaseVector(FightingVegetable::_objsList);
	QObject::releaseVector(Pest::_objsList);

	//清理图层
	_vegetableLayer->removeAllChildrenWithCleanup(true);
	_vegetableLayer->removeFromParentAndCleanup(true);
	_pestLayer->removeAllChildrenWithCleanup(true);
	_pestLayer->removeFromParentAndCleanup(true);
	_particleLayer->removeAllChildrenWithCleanup(true);
	_particleLayer->removeFromParentAndCleanup(true);
}

void GameScene::plant(Coordinate c)
{
	showPlantItems(true);
	_plantC = c;
}

void GameScene::showPlantItems(bool isShow)
{
	_plantLayer->setVisible(isShow);
}; 

void GameScene::pause(Ref* sender)
{
	_pause_item->setVisible(false);

	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	
	QScene::saveNowSceneToFile();

	auto pause = [](float dt)
	{
		Scene* scene = PauseScene::createPauseScene();
		Director::getInstance()->pushScene(scene);
	};

	auto schedules = this->getScheduler();//获取调度对象
	schedules->schedule(pause, this, 0.0f, 0, 0.0f, false, "pause_screen");
}

void GameScene::initMenuItems()
{
	Vector<MenuItem*> items;

	//创建暂停游戏精灵菜单项
	_pause_item = QMenu::createMenuItemSprite("pause.png", QE_CALLBACK_1(GameScene, pause));
	_pause_item->setPosition(Vec2(winSize.width - _pause_item->getContentSize().width / 2 - 10, winSize.height - _pause_item->getContentSize().height / 2 - 10));
	items.pushBack(_pause_item);

	//创建种植蔬菜的精灵菜单项
	MenuItem* item;
	Coordinate c;
	for (size_t i = 0, length = _coordinates.size(); i < length; i++)
	{
		c = _coordinates.at(i);
		item = QMenu::createMenuItemSprite("plant.png", bind(&GameScene::plant, c), 5, 5);
		item->setPosition(c.x, c.y);
		item->setScale(0.5);
		item->setScaleX(0.6);
		item->setScaleY(0.56);
		item->setScaleZ(0.5);
		item->setRotation(30);
		items.pushBack(item);
		_plantItems.push_back(item);
	}

	QE_addMenuToThis;

	initPlantItems();
}

void GameScene::initPlantItems() 
{
	//声明临时变量
	Sprite* _plantBg;
	Coordinate c;
	string fileName, tmxFile = SelectLevelScene::_levelName + ".tmx";

	//添加背景精灵
	fileName = "plantBg_" + SelectLevelScene::_levelName + ".png";
	_plantBg = Sprite::create(fileName);
	QTMX::initCoordinatesByTMXFile(c, tmxFile, "bg");
	_plantBg->setPosition(c.x, c.y);
	_plantLayer->addChild(_plantBg);

	Vector<MenuItem*> items;
	MenuItem* item;
	fileName = "plant_" + CurrentLevelData::_aimedVegetableType.name + ".png";
	item = QMenu::createMenuItemSprite(fileName, bind(&Vegetable::plantAimedVegetables), 0, 5);
	QTMX::initCoordinatesByTMXFile(c, tmxFile, CurrentLevelData::_aimedVegetableType.name);
	item->setPosition(c.x, c.y);
	items.pushBack(item);

	CurrentLevelData::_fightingVegetableTypes;
	CurrentLevelData::_pestTypes;
	FightingVegetableType fT;
	for (size_t i = 0, length = CurrentLevelData::_fightingVegetableTypes.size(); i < length; i++)
	{
		fT = CurrentLevelData::_fightingVegetableTypes.at(i);
		fileName = "plant_" + fT.name + ".png";
		item = QMenu::createMenuItemSprite(fileName, bind(Vegetable::plantFightingVegetables, fT.name), 0, 5);
		QTMX::initCoordinatesByTMXFile(c, tmxFile, fT.name);
		item->setPosition(c.x, c.y);
		items.pushBack(item);
	}

	QE_addMenuTo(_plantLayer);

	showPlantItems();
}

void GameScene::initLayers()
{
	createBlankLayerAndAddToThis(_vegetableLayer);
	createBlankLayerAndAddToThis(_pestLayer);
	createBlankLayerAndAddToThis(_particleLayer);
	createBlankLayerAndAddToThis(_plantLayer, 1);

	_timeLayer = TimeLayer::create();
	addChild(_timeLayer, 1);
}
void GameScene::createBlankLayerAndAddToThis(Layer*& layer, int order)
{
	layer = Layer::create();
	addChild(layer, order);
}

void GameScene::initCoordinates()
{
	if (!_coordinates.empty()) { return; };
	QTMX::initCoordinatesByTMXFile(_coordinates, "plantLand.tmx", "land");
}