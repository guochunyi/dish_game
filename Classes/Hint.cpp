#include "Hint.h"
#include "Helper.h"
#include "Food.h"

USING_NS_CC;

std::array<std::string, 6> Hint::hints = {"c_09.png", "c_10.png", "c_11.png"};

Hint::Hint(FoodType t) : type(t)
{
}

bool Hint::init()
{
	if (!Node::init())
	{
		return false;
	}
	hint = Sprite::create(hints[(int) type]);
	back = Sprite::create(hints[2]);
	this->addChild(back);
	this->addChild(hint);
	return true;
}

void Hint::setHint(FoodType t)
{
	if (t == type)
	{ 
		return;
	}
	type = t;
	hint->stopAllActions();
	hint->runAction(
		Sequence::create(FadeOut::create(0.3f) , CallFunc::create([this]()
		{
			this->removeChild(hint);
			hint = Sprite::create(hints[(int) type]);
			this->addChild(hint);
			hint->runAction(FadeIn::create(0.3f));
	}), nullptr));
}

FoodType Hint::getType() const
{
	return type;
}