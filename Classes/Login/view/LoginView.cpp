//
//  LoginView.cpp
//  cocos_c++_mvp-mobile
//
//  Created by HelyLi on 2018/1/3.
//

#include "LoginView.hpp"
#include "LoginPresenter.hpp"


// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

LoginView::LoginView() {
    new LoginPresenter(this);
}

void LoginView::setPresenter(Presenter * const p) {
    presenter = p;
}

LoginView::~LoginView(){
    
}

void LoginView::updateInfo() { 
    printf("LoginView::updateInfo\n");
}

void LoginView::initTouchEvent() { 
    _touchEventListener = EventListenerTouchOneByOne::create();
    
    _touchEventListener->onTouchBegan = CC_CALLBACK_2(LoginView::onTouchBegan, this);
    _touchEventListener->onTouchMoved = CC_CALLBACK_2(LoginView::onTouchMoved, this);
    _touchEventListener->onTouchEnded = CC_CALLBACK_2(LoginView::onTouchEnded, this);
    _touchEventListener->onTouchCancelled = CC_CALLBACK_2(LoginView::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchEventListener, this);
}

void LoginView::onExit() { 
    Layer::onExit();
    _eventDispatcher->removeEventListener(_touchEventListener);
}

void LoginView::onEnter() { 
    Layer::onEnter();
}

bool LoginView::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    return presenter->onTouchBegan(touch, unused_event);
}

void LoginView::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) { 
    presenter->onTouchEnded(touch, unused_event);
}

void LoginView::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) { 
    presenter->onTouchMoved(touch, unused_event);
}

void LoginView::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event) { 
    presenter->onTouchCancelled(touch, unused_event);
}

bool LoginView::init() { 
    
    if (!Layer::init()) {
        return false;
    }
    initTouchEvent();
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(LoginView::menuCloseCallback, this));
    
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));
        
        // add the label as a child to this layer
        this->addChild(label, 1);
    }
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    
    return true;
}


void LoginView::menuCloseCallback(Ref* pSender)
{
    presenter->checkUpdate();
    //Close the cocos2d-x game scene and quit the application
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}












