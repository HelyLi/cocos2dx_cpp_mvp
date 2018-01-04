//
//  LoginView.hpp
//  cocos_c++_mvp-mobile
//
//  Created by HelyLi on 2018/1/3.
//

#ifndef LoginView_hpp
#define LoginView_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "LoginContract.h"

#include "LoginPresenter.hpp"

class Presenter;
class View;


class LoginView : public Layer, View {
private:
    Presenter *presenter;
    EventListenerTouchOneByOne *_touchEventListener;
public:
    
//    static LoginView* create();
    CREATE_FUNC(LoginView);
    
    LoginView();
    ~LoginView();
    
    virtual bool init();
    
    virtual void setPresenter(Presenter * const p);
    virtual void updateInfo();
    
    virtual void onEnter();
    virtual void onExit();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
protected:
    void initTouchEvent();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
};


#endif /* LoginView_hpp */



