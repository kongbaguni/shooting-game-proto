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
    
//    배경 레이어 초기화
    auto bg = Layer::create();
    Vec3 r = CUtil::getRotate3D();
    bg->setRotation3D(Vec3(-r.x, 0, 0));
    bg->setPosition(Vec2(0.0f,150.0f));
    addChild(bg);
    
//    타일맵 초기화
    auto tileMap = TMXTiledMap::create("tilemap/map.tmx");
    CSetting::getinstance()->setTileMap(tileMap);
    
    tileMap->setPosition(Vec2(0,-winsize.height/2));
    for (const auto& child : tileMap->getChildren())
    {
        static_cast<SpriteBatchNode*>(child)->getTexture()->setAntiAliasTexParameters();
    }
    tileMap->setPosition3D(Vec3(0.0f, -winsize.height, 0.0f));
    bg->addChild(tileMap);
    
//    게임매니져 붙이기
    addChild(CGameManager::getInstance());
    
//    리소스 로딩
    std::string fileName = CUtil::getHDSDname("texturePacker/unit%s.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName);

//    플레이어 초기화
    auto player = CPlayerSprite::create();
    player->setPosition(winsize.width/2,10);
    bg->addChild(player);
    
    
    return true;
}