#ifndef __FOOD_H__
#define __FOOD_H__

#include "cocos2d.h"
#include <iostream>

enum class FoodType : int {
	typeRice,
	typeCurry
};

class Food : public cocos2d::Node
{
	const float SPEED = 1200.f;
public:
	Food(FoodType type);
    virtual bool init();
    void update(float delta);
	cocos2d::Size getSize() const;
	FoodType type;
    
private:
	cocos2d::Sprite *sprite;
};

#endif /* defined(__FOOD_H__) */
