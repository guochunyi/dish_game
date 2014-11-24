#include "DishSprite.h"

#include "HelloWorldScene.h"

USING_NS_CC;

HelloWorld* HelloWorld::_singleton = NULL;

HelloWorld* HelloWorld::getInstance()
{
    return _singleton;
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    _singleton = layer;

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    this->schedule(schedule_selector(HelloWorld::createDish), 1);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    auto backgroundImage = Sprite::create("c_19.png");
    backgroundImage->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    backgroundImage->setScale(1.34, 1.2);
    this->addChild(backgroundImage, kZOrderBackground);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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

void HelloWorld::createDish(float delta)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    auto dish = Dish::create();
    dish->setPosition(Point(visibleSize.width + dish->getContentSize().width/2, visibleSize.height * 0.2));
    this->addChild(dish, kZOrderDish);
}

void HelloWorld::endGame()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    {
        auto endTest = Sprite::create("c_21.png");
        endTest->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
        this->addChild(endTest, 200000);
    }
    else
    {
        auto endTest = Sprite::create("img/c_21.png");
        endTest->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
        this->addChild(endTest, 200000);
    }
}
