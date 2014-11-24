//
//  FoodSprite.cpp
//  MyGame
//
//  Created by guo chunyi on 2014/11/23.
//
//

#include "FoodSprite.h"

USING_NS_CC;

bool Food::init()
{
    if(!Sprite::initWithFile("c_10"))
    {
        return false;
    }
    
    mSpeed = Point(0.f, -10.f);
    
    return true;
}
