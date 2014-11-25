#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "SimpleAudioEngine.h"
#include "cocos2d.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
using namespace CocosDenshion;
class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();
private:
    const int DESIGN_WIDTH = 540;
    const int DESIGN_HEIGHT = 960;
};

#endif // _APP_DELEGATE_H_

