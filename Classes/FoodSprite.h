//
//  FoodSprite.h
//  MyGame
//
//  Created by guo chunyi on 2014/11/23.
//
//

#ifndef __MyGame__FoodSprite__
#define __MyGame__FoodSprite__

#include "cocos2d.h"
#include <iostream>

class Food : public cocos2d::Sprite
{
public:
    //init
    virtual bool init();
    //dish handle method
    CREATE_FUNC(Food);
    
private:
    cocos2d::Point mSpeed;
};

#endif /* defined(__MyGame__FoodSprite__) */
