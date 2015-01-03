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
_vec2TouchMovement(Vec2(0.0f,0.0f)),
_pPlayerSprite(NULL)
{
    EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    //터치 리스너 등록
    {
        auto touchListner = EventListenerTouchOneByOne::create();
        touchListner->setSwallowTouches(true);
        touchListner->onTouchBegan = CC_CALLBACK_2(CGameManager::onTouchBegan, this);
        touchListner->onTouchMoved = CC_CALLBACK_2(CGameManager::onTouchMoved, this);
        touchListner->onTouchEnded = CC_CALLBACK_2(CGameManager::onTouchEnded, this);
        touchListner->onTouchCancelled = CC_CALLBACK_2(CGameManager::onTouchCancelled, this);
        dispatcher->addEventListenerWithSceneGraphPriority(touchListner, this);
    }
    //키보드 리스너 등록
    {
        auto keyboardListener = EventListenerKeyboard::create();
        keyboardListener->setEnabled(true);
        keyboardListener->onKeyPressed = CC_CALLBACK_2(CGameManager::onKeyPressed, this);
        keyboardListener->onKeyReleased = CC_CALLBACK_2(CGameManager::onKeyReleased, this);
        dispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    }
 
    
    
    
    memset(_baArrowPress, false, sizeof(_baArrowPress));
    
    
}
CGameManager::~CGameManager()
{
    CC_SAFE_RELEASE_NULL(_pPlayerSprite);
    
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

void CGameManager::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    float fPlayerSpeed = 5;
    switch (keyCode) {
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            _vec2TouchMovement.y = fPlayerSpeed;
            _baArrowPress[0] = true;
            unschedule(schedule_selector(CGameManager::scheduleStopMovement));
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            _vec2TouchMovement.y = -fPlayerSpeed;
            _baArrowPress[1] = true;
            unschedule(schedule_selector(CGameManager::scheduleStopMovement));
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            _vec2TouchMovement.x = -fPlayerSpeed;
            _baArrowPress[2] = true;
            unschedule(schedule_selector(CGameManager::scheduleStopMovement));
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            _vec2TouchMovement.x = fPlayerSpeed;
            _baArrowPress[3] = true;
            unschedule(schedule_selector(CGameManager::scheduleStopMovement));
            break;
        default:
            break;
    }
    CCLOG("keyDown");
    
}
void CGameManager::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    //방향키검사
    switch (keyCode) {
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
            _baArrowPress[0] = false;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            _baArrowPress[1] = false;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            _baArrowPress[2] = false;
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            _baArrowPress[3] = false;
            break;
        default:
            break;
    }
    int iKeyTest = 0;
    for (int i=0; i<4; i++)
    {
        iKeyTest+=(int)_baArrowPress[i];
    }
    if(iKeyTest==0)
    {
        schedule(schedule_selector(CGameManager::scheduleStopMovement));
    }

    //점프 
    switch (keyCode) {
        case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
            _pPlayerSprite->jumpAction();
            break;
        default:
            break;
    }
}

void CGameManager::scheduleStopMovement(float dt)
{
    _vec2TouchMovement.x*=0.9f;
    _vec2TouchMovement.y*=0.9f;
    float fMovementSize = fabsf(_vec2TouchMovement.x)+fabsf(_vec2TouchMovement.y);
    if(fMovementSize<=0.1f)
    {
        _vec2TouchMovement = Vec2(0.0f,0.0f);
        unschedule(schedule_selector(CGameManager::scheduleStopMovement));
    }
}
