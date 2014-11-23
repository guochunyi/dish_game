//
//  DishSprite.h
//  MyGame
//
//  Created by guo chunyi on 2014/11/22.
//
//

#ifndef __MyGame__DishSprite__
#define __MyGame__DishSprite__

#include "cocos2d.h"
#include <iostream>

class Dish : public cocos2d::Sprite
{
public:
    //init
    virtual bool init();
    //
    void locations(float location_x, float location_y);
    void moveAction();
    
    void handleDish();
    void update(float delta);
    
    CREATE_FUNC(Dish);
    
private:
    cocos2d::Point mSpeed;
};

#endif /* defined(__MyGame__DishSprite__) */
