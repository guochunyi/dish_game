//
//  FoodSprite.cpp
//  MyGame
//
//  Created by guo chunyi on 2014/11/23.
//
//

#include "Food.h"
#include "GameLayer.h"
#include "Dish.h"

USING_NS_CC;

Food::Food(FoodType _type): type(_type)
{
}

bool Food::init()
{
    if(!Node::init())
    {
        return false;
    }
	if (type == FoodType::typeRice)
	{
		sprite = Sprite::create("c_08.png");
	}
	else
	{
		sprite = Sprite::create("c_07.png");
	}
	sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	this->addChild(sprite);
    this->scheduleUpdate();
	this->setCascadeOpacityEnabled(true);
	return true;
}

void Food::update(float delta)
{
	this->setPositionY(this->getPositionY() - SPEED * delta);
	if (this->getPositionY() < 0)
	{
		this->cleanup();
		this->getParent()->removeChild(this);
		return;
	}
	for (Dish *dish : GameLayer::getInstance()->dishList)
	{
		if (dish->checkHit(this, SPEED * delta))
		{
			dish->putFood(this);
			this->cleanup();
			this->getParent()->removeChild(this);
			return;
		}
	}
}

Size Food::getSize() const
{
	return sprite->getContentSize();
}