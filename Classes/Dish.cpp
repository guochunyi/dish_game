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
	isLive = true;
	setAnchorPoint(Vec2(0.5f, 0.5f));
    mSpeed = Point(-200.f, 0.f);
    this->scheduleUpdate();
	sprite = Sprite::create(dishes[(int)DishType::empty]);
	this->addChild(sprite);
	type = DishType::empty;
	minX = -50;
	maxX = Director::getInstance()->getWinSize().width + 50;
	maxY = 650;
	setCascadeOpacityEnabled(true);
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
    Point point = this->getPosition();
    if(point.x < minX || point.x > maxX)
    {
        this->setPositionY(this->getPositionY() + 80.0f);
        if(isLive && point.y > maxY)
        {
            GameLayer::getInstance()->endGame();
        };
        mSpeed = -mSpeed;
		this->setPositionX(mSpeed.x > 0 ? minX : maxX);
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
			GameLayer::getInstance()->endGame();
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
			GameLayer::getInstance()->addScore(100);
			disappear();
		}
		break;
	case::DishType::doubleRice:
		if (food->type == FoodType::typeRice)
		{
			GameLayer::getInstance()->endGame();
		}
		else
		{
			changeType(DishType::curryDoubleRice);
			GameLayer::getInstance()->addScore(200);
			disappear();
		}
		break;
	}
}

void Dish::disappear()
{
	isLive = false;
	CCActionInterval* action = FadeOut::create(0.5);
	GameLayer::getInstance()->dishList.remove(this);
	this->runAction(
		Sequence::create(action, CallFunc::create([this]()
		{
			this->pause();
			this->getParent()->removeChild(this);
		}), nullptr)
	);
}