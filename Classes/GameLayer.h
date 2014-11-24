#ifndef __GAME_LAYER_SCENE_H__
#define __GAME_LAYER_SCENE_H__

#include "cocos2d.h"
#include "Helper.h"
#include <forward_list>
class Dish;
class GameLayer : public cocos2d::Layer, public SingleInstance<GameLayer>
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();  
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void createDish(float delta);
    
    void endGame();
    
    CREATE_FUNC(GameLayer);
    
	std::forward_list<Dish*> dishList;
private:
	
    enum kZOrder
    {
        kZOrderBackground = 0,
        kZOrderDish,
        kZOrderMenu,
    };
};

#endif // __GAME_LAYER_SCENE_H__
