//
//  Dish.h
//  MyGame
//
//  Created by guo chunyi on 2014/11/22.
//
//

#ifndef __MyGame__Dish__
#define __MyGame__Dish__

#include "cocos2d.h"
#include <array>
class Food;
enum class DishType : int
{
	empty = 0,
	curry,
	singleRice,
	doubleRice,
	currySingleRice,
	curryDoubleRice
};

class Dish : public cocos2d::Node
{
public:
    //init
    virtual bool init();
    
    //dish handle method
    void handleDish();
    void update(float delta);
	bool checkHit(Food *food, float delta) const;
	void putFood(Food *food);
	void changeType(DishType targetType);
	void disappear();
private:
	float minX, maxX, maxY;
    cocos2d::Point mSpeed;
	static std::array<std::string, 6> dishes;
	cocos2d::Sprite *sprite;
	DishType type;
};

#endif /* defined(__MyGame__Dish__) */
