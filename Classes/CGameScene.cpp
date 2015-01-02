//
//  CGameScene.cpp
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 2..
//
//

#include "CGameScene.h"
#include "CPlayerSprite.h"
#include "CUtil.h"
bool CGameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    Size winsize = Director::getInstance()->getWinSize();
    
    auto bg = LayerColor::create(Color4B(255,255,255,255));
    addChild(bg);
    
    std::string fileName = CUtil::getHDSDname("texturePacker/unit%s.plist");
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName);

    
    auto player = CPlayerSprite::create();
    player->setPosition(winsize.width/2,winsize.height/2);
    addChild(player);
    
    
    return true;
}