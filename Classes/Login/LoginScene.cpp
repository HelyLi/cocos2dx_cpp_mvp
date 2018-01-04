//
//  LoginScene.cpp
//  cocos_c++_mvp-mobile
//
//  Created by HelyLi on 2018/1/3.
//

#include "LoginScene.hpp"
#include "LoginView.hpp"

LoginScene::LoginScene() { 
    
}

LoginScene::~LoginScene() {
    
}

bool LoginScene::init() {
    
    if ( !Scene::init() )
    {
        return false;
    }
    
    this->addChild(LoginView::create());
    
    return true;
}


