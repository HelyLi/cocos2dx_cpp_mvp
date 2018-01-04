//
//  LoginScene.hpp
//  cocos_c++_mvp-mobile
//
//  Created by HelyLi on 2018/1/3.
//

#ifndef LoginScene_hpp
#define LoginScene_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class LoginScene : public Scene {
public:
    LoginScene();
    ~LoginScene();
    
    virtual bool init();
    
    CREATE_FUNC(LoginScene);
};


#endif /* LoginScene_hpp */
