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
#include "CGameManager.h"

bool CGameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    Size winsize = Director::getInstance()->getWinSize();
    
    float fRotate = 90.0f;
    
    auto bg = Layer::create();
    bg->setRotation3D(Vec3(-fRotate, 0, 0));
    bg->setPosition(Vec2(0.0f,winsize.height/2.0f));
    
    for (const auto& child : bg->getChildren())
    {
        static_cast<SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
    }
    addChild(bg);

    addChild(CGameManager::getInstance());
    
    
    std::string fileName = CUtil::getHDSDname("texturePacker/unit%s.plist");
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName);

    
    auto player = CPlayerSprite::create();
    player->setPosition(winsize.width/2,winsize.height/3);
    player->setRotation3D(Vec3(fRotate, 0, 0));
    bg->addChild(player);
    
    
    return true;
}