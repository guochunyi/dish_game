//
//  DishSprite.cpp
//  MyGame
//
//  Created by guo chunyi on 2014/11/22.
//
//

#include "GameLayer.h"

#include "Dish.h"
#include "Helper.h"
#include "Food.h"

USING_NS_CC;

std::array<std::string, 6> Dish::dishes = { "c_01.png", "c_04.png", "c_02.png", "c_17.png", "c_03.png", "c_18.png" };

bool Dish::init()
{
    
    if (!Node::init())
    {
        return false;
    }
	setAnchorPoint(Vec2(0.5f, 0.5f));
    mSpeed = Point(-100.f, 0.f);
    this->scheduleUpdate();
	sprite = Sprite::create(dishes[(int)DishType::empty]);
	this->addChild(sprite);
	type = DishType::empty;
/*	sprites[(int) DishType::empty] = "c_01.png";
	sprites[(int) DishType::curry] = "c_04.png";
	sprites[(int) DishType::singleRice] = "c_02.png";
	sprites[(int) DishType::doubleRice] = "c_17.png";
	sprites[(int) DishType::currySingleRice] = "c_03.png";
	sprites[(int) DishType::curryDoubleRice] = "c_18.png";*/
	return true;
}

void Dish::update(float delta)
{
    handleDish();
    this->setPosition(this->getPosition() + mSpeed * delta);
}

void Dish::handleDish()
{
    // TODO: 位置を判断する
    Point point = this->getPosition();
    this->setAnchorPoint(Point(1, 0));
    if(point.x < -20 || point.x > Director::getInstance()->getWinSize().width + 100)
    {
        this->setPosition(this->getPosition() + Point(0.f, 80.0f));
        if(point.y > Director::getInstance()->getWinSize().height * 0.65f)
        {
            GameLayer::getInstance()->endGame();
        };
        mSpeed = -mSpeed;
    }
}

bool Dish::checkHit(Food *food, float delta) const
{
	Vec2 pos = food->getPosition() - this->getPosition() - Vec2(0, 32);
	if (pos.y >= 0 || pos.y <= -delta - 30)
	{
		return false;
	}
	Size hitSize = Size(50, 50);
	
	if (pos.x < hitSize.width && pos.x > -hitSize.width)
	{
		return true;
	}
	return false;
}

void Dish::changeType(DishType targetType)
{
	if (targetType == type)
	{
		return;
	}
	this->removeChild(sprite);
	sprite = Sprite::create(dishes[(int)targetType]);
	this->addChild(sprite);
	type = targetType;
}

void Dish::putFood(Food *food)
{
	switch (type)
	{
	case::DishType::empty:
		if (food->type == FoodType::typeRice)
		{
			changeType(DishType::singleRice);
		}
		else
		{
			changeType(DishType::curry);
		}
		break;
	case::DishType::singleRice:
		if (food->type == FoodType::typeRice)
		{
			changeType(DishType::doubleRice);
		}
		else
		{
			changeType(DishType::currySingleRice);
		}
		break;
	case::DishType::doubleRice:
		if (food->type == FoodType::typeRice)
		{
			break;
		}
		else
		{
			changeType(DishType::curryDoubleRice);
		}
		break;
	}
}