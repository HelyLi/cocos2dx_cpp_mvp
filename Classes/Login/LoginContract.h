//
//  LoginContract.h
//  cocos_c++_mvp
//
//  Created by HelyLi on 2018/1/3.
//

#ifndef LoginContract_h
#define LoginContract_h

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class Presenter{
public:
    virtual void checkUpdate() = 0;
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event) = 0;
    virtual void onTouchMoved(Touch *touch, Event *unused_event) = 0;
    virtual void onTouchEnded(Touch *touch, Event *unused_event) = 0;
    virtual void onTouchCancelled(Touch *touch, Event *unused_event) = 0;
};

class View {
public:
    virtual void setPresenter(Presenter * const p) = 0;
    virtual void updateInfo() = 0;
};

#endif /* LoginContract_h */
