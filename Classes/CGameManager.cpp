//
//  CGameManager.cpp
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 3..
//
//

#include "CGameManager.h"
CGameManager::CGameManager():
_vec2TouchPoint(Vec2(0.0f,0.0f)),
_vec2TouchMovement(Vec2(0.0f,0.0f))
{
    auto touchListner = EventListenerTouchOneByOne::create();
    touchListner->setSwallowTouches(true);
    touchListner->onTouchBegan = CC_CALLBACK_2(CGameManager::onTouchBegan, this);
    touchListner->onTouchMoved = CC_CALLBACK_2(CGameManager::onTouchMoved, this);
    touchListner->onTouchEnded = CC_CALLBACK_2(CGameManager::onTouchEnded, this);
    touchListner->onTouchCancelled = CC_CALLBACK_2(CGameManager::onTouchCancelled, this);
    
    EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(touchListner, this);
}
CGameManager::~CGameManager()
{
    
}

bool CGameManager::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    return true;
}

CGameManager* CGameManager::getInstance()
{
    static CGameManager* instance = NULL;
    if(instance==NULL)
    {
        instance = new CGameManager();
        instance->init();
    }
    return instance;
}

bool CGameManager::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    _vec2TouchPoint = touch->getLocation();

    
 
    return true;
}

void CGameManager::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    Vec2 touchPoint = touch->getLocation();
    _vec2TouchMovement =  touchPoint - _vec2TouchPoint;
    _vec2TouchPoint = touchPoint;
    
}

void CGameManager::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    onTouchMoved(touch, unused_event);
    _vec2TouchMovement = Vec2(0.0f, 0.0f);
    
}
void CGameManager::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    onTouchMoved(touch, unused_event);
    _vec2TouchMovement = Vec2(0.0f, 0.0f);
}

