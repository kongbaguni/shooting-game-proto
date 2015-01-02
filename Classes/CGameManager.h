//
//  CGameManager.h
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 3..
//
//

#ifndef __shootinggamePrototype__CGameManager__
#define __shootinggamePrototype__CGameManager__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class CGameManager : public Layer
{
public:
    virtual bool init();
    static CGameManager* getInstance();
private:
    CGameManager();
    virtual ~CGameManager();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
    
    CC_SYNTHESIZE_READONLY(Vec2, _vec2TouchPoint,TouchStartPoint);
    CC_SYNTHESIZE_READONLY(Vec2, _vec2TouchMovement, TouchMovement);
    
    
};

#endif /* defined(__shootinggamePrototype__CGameManager__) */
