#ifndef __GAME_LAYER_SCENE_H__
#define __GAME_LAYER_SCENE_H__

#include "cocos2d.h"
#include "Helper.h"
#include <forward_list>
#include <random>

class Dish;
class Hint;
class GameLayer : public cocos2d::Layer, public SingleInstance<GameLayer>
{
protected:
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();  
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void createDish(float delta);
    void endGame();
    
	void addScore(int _score);

    CREATE_FUNC(GameLayer);
    
	std::forward_list<Dish*> dishList;
	void update(float delta);
private:
	Hint* nextHint;
	int64_t score;
	int64_t showScore;
	cocos2d::LabelBMFont *scoreText;
	std::mt19937 randEngine;
    enum kZOrder
    {
        kZOrderBackground = 0,
        kZORderStartbutton,
        kZOrderDish,
        kZOrderMenu,
    };
};

#endif // __GAME_LAYER_SCENE_H__
