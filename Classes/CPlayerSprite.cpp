//
//  CPlayerSprite.cpp
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 2..
//
//

#include "CPlayerSprite.h"
#include "CAnimationHelper.h"
#include "CUtil.h"
CPlayerSprite::CPlayerSprite(void) :
m_pSprite(NULL)
{
    
    
}
CPlayerSprite::~CPlayerSprite(void)
{
    CC_SAFE_RELEASE_NULL(m_pSprite);
}

bool CPlayerSprite::init()
{
    if(!Node::init())
    {
        return false;
    }
//    CAnimationHelper::addAnimation("unit/c1_%02d.png", 1, 2, "player_stand");
//    CAnimationHelper::addAnimation("unit/c1_%02d.png", 3, 4, "player_down");
//    CAnimationHelper::addAnimation("unit/c1_%02d.png", 4, 3, "player_up");
//    

    setSprite(Sprite::createWithSpriteFrameName("unit/c1_01.png"));
    addChild(m_pSprite);
    
    
    return true;
}

void CPlayerSprite::update(float dt)
{
    
}

