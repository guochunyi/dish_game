//
//  Food.h
//  MyGame
//
//  Created by guo chunyi on 2014/11/23.
//
//

#ifndef __MyGame__Food__
#define __MyGame__Food__

#include "cocos2d.h"
#include <iostream>

enum class FoodType : int {
	typeRice,
	typeCurry
};

class Food : public cocos2d::Node
{
	const float SPEED = 600.f;
public:
	Food(FoodType type);
    virtual bool init();
    void update(float delta);
	cocos2d::Size getSize() const;
	FoodType type;
    
private:
	cocos2d::Sprite *sprite;
};

#endif /* defined(__MyGame__Food__) */
