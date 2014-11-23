//
//  DishSprite.cpp
//  MyGame
//
//  Created by guo chunyi on 2014/11/22.
//
//

#include "HelloWorldScene.h"

#include "DishSprite.h"

USING_NS_CC;

bool Dish::init()
{
    
    if (!Sprite::initWithFile("c_01.png"))
    {
        
        return false;
        
    }

    mSpeed = Point(-10.f, 0.f);
    this->scheduleUpdate();
    
    return true;
}

void Dish::update(float delta)
{
    handleDish();
    this->setPosition(this->getPosition() + mSpeed);
}

void Dish::handleDish()
{
    // TODO: 碟子的位置判断
    Point point = this->getPosition();
    this->setAnchorPoint(Point(1, 0));
    if(point.x < -20 || point.x > Director::getInstance()->getWinSize().width + 50)
    {
        this->setPosition(this->getPosition() + Point(0.f, 80.0f));
        if(point.y > Director::getInstance()->getWinSize().height * 0.7)
        {
            HelloWorld::getInstance()->endGame();
        };
        mSpeed = -mSpeed;
    }
    
    
}