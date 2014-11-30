#ifndef __HINT_H__
#define __HINT_H__

#include "cocos2d.h"
#include "Food.h"
#include <array>

class Hint : public cocos2d::Node
{
public:
    virtual bool init();
	void setHint(FoodType t);
	FoodType getType() const;
	Hint(FoodType t);
private:
	cocos2d::Sprite *hint;
	cocos2d::Sprite *back;
	FoodType type;
	static std::array<std::string, 6> hints;
};

#endif /* defined(__HINT_H__) */
