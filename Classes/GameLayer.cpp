#include "GameLayer.h"
#include "Dish.h"
#include "Food.h"
USING_NS_CC;

Scene* GameLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music.mp3",true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto backgroundImage = Sprite::create("c_19.png");
    auto startButton = Sprite::create("c_20.png");
    startButton->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    backgroundImage->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    backgroundImage->setScale(1.34, 1.2);
    this->addChild(startButton, kZORderStartbutton);
    this->addChild(backgroundImage, kZOrderBackground);
    
    //1秒かけてフェードアーウト
    CCActionInterval* action = CCFadeOut::create(3);
    startButton->runAction(action);
    this->removeChild(startButton);
    
    //game start
    auto listenerStart = EventListenerTouchAllAtOnce::create();
    listenerStart->onTouchesBegan = CC_CALLBACK_2(GameLayer::onTouchesBegan,this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerStart, this);
    
    this->schedule(schedule_selector(GameLayer::createDish), 3);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameLayer::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

	auto listener = EventListenerTouchOneByOne::create();
	static int nextFood = 0;
	listener->onTouchBegan = [this](Touch *touch, Event *event) {
		Vec2 location = touch->getLocation();
		Food* food = Create<Food>((FoodType)((++nextFood)&1));
		food->setPosition(Vec2(location.x, 960));
		this->addChild(food);
		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}


void GameLayer::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameLayer::createDish(float delta)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    auto dish = Create<Dish>();
    dish->setPosition(Point(visibleSize.width + dish->getContentSize().width/2, visibleSize.height * 0.2));
    this->addChild(dish, kZOrderDish);
	dishList.push_front(dish);
}

void GameLayer::endGame()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto endTest = Sprite::create("c_21.png");
    endTest->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    //stop the schedules
    this->addChild(endTest, 200000);
    
    for (Dish* dish : this->dishList)
    {
        dish->pause();
    }
    this->pause();
    
}
