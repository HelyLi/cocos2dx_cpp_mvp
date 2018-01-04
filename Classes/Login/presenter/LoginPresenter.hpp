//
//  LoginPresenter.hpp
//  cocos_c++_mvp-mobile
//
//  Created by HelyLi on 2018/1/3.
//

#ifndef LoginPresenter_hpp
#define LoginPresenter_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "LoginContract.h"

using namespace cocos2d;

class Presenter;
class View;

class LoginPresenter : public Presenter{
private:
    View *view;
public:
    
    LoginPresenter(View * const v);
    ~LoginPresenter();

    void checkUpdate();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
};

#endif /* LoginPresenter_hpp */
