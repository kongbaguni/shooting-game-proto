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
#include "CGameManager.h"

CPlayerSprite::CPlayerSprite(void) :
_pSprite(NULL),
_pLabel(NULL)
{
    
    
}
CPlayerSprite::~CPlayerSprite(void)
{
    CC_SAFE_RELEASE_NULL(_pSprite);
    CC_SAFE_RELEASE_NULL(_pLabel);
}

bool CPlayerSprite::init()
{
    if(!Node::init())
    {
        return false;
    }
    CAnimationHelper::addAnimation("unit/c1_%02d.png", 1, 2, "player_stand",0.2f,true);
    CAnimationHelper::addAnimation("unit/c1_%02d.png", 3, 4, "player_down",0.2f,true);
    CAnimationHelper::addAnimation("unit/c1_%02d.png", 4, 3, "player_up",0.2f,true);

    setSprite(Sprite::createWithSpriteFrameName("unit/c1_01.png"));
    addChild(_pSprite);
    setLabel(Label::createWithBMFont(CUtil::getHDSDname("fonts/title%s.fnt"), "0 : 0"));
    addChild(_pLabel);
    _pLabel->setScale(0.5f);
    
    scheduleUpdate();
    standAction();
    return true;
}

void CPlayerSprite::standAction()
{
    auto action =_pSprite->getActionByTag((int)actionTag::STAND);
    if(action && !action->isDone())
    {
        return;
    }
    auto animation = AnimationCache::getInstance()->getAnimation("player_stand");
    auto ani = RepeatForever::create(Animate::create(animation));
    
    auto jump = RepeatForever::create
    (Sequence::create
     (MoveTo::create(1.0f, Vec2(0.0f,10.0f)),
      MoveTo::create(1.0f, Vec2(0.0f,0.0f)),
      NULL));
    
    ani->setTag((int)actionTag::STAND);
    _pSprite->runAction(ani);
    jump->setTag((int)actionTag::STAND);
    _pSprite->runAction(jump);
    

    
}
void CPlayerSprite::jumpAction()
{
    
}

void CPlayerSprite::update(float dt)
{
    if(CGameManager::getInstance()->getParent()==NULL)
    {
        return;
    }
    Vec2 pos = getPosition();
    _pLabel->setString(String::createWithFormat("%0.2f : %0.2f",pos.x, pos.y)->_string);
    
    Size winsize = Director::getInstance()->getWinSize();
    const Vec2 movement = CGameManager::getInstance()->getTouchMovement();
    Vec2 prePos = pos+movement;
    if(prePos.y>winsize.height/2-10.0f | prePos.y<-winsize.height/2 | prePos.x<0 | prePos.x>winsize.width)
    {
        return;
    }
    
        
    this->setPosition(this->getPosition()+movement);
    
    
    if(movement.x<0)
    {
        _pSprite->setFlippedX(false);
    }
    else if(movement.x > 0)
    {
        _pSprite->setFlippedX(true);
    }
    
    
    
    
}

