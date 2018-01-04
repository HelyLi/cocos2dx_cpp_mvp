//
//  LoginPresenter.cpp
//  cocos_c++_mvp-mobile
//
//  Created by HelyLi on 2018/1/3.
//

#include "LoginPresenter.hpp"

LoginPresenter::LoginPresenter(View * const view) {
    this->view = view;
    this->view->setPresenter(this);
}

LoginPresenter::~LoginPresenter() {
    
}

void LoginPresenter::checkUpdate() { 
    printf("LoginPresenter::checkUpdate\n");
    
    view->updateInfo();
}

bool LoginPresenter::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) { 
    printf("LoginPresenter::onTouchBegan\n");
    return true;
}

void LoginPresenter::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) { 
    printf("LoginPresenter::onTouchMoved\n");
}

void LoginPresenter::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) { 
    printf("LoginPresenter::onTouchEnded\n");
}

void LoginPresenter::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event) { 
    printf("LoginPresenter::onTouchCancelled\n");
}






