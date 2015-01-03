//
//  CUtil.h
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 2..
//
//

#ifndef __shootinggamePrototype__CUtil__
#define __shootinggamePrototype__CUtil__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class CUtil
{
public:
    
    static bool isHD();
    static std::string getHDSD();
    static std::string getHDSDname(std::string nameFormat);
    static Vec3 getRotate3D();
};

class CSetting
{
public:
    static CSetting* getinstance();
private:
    CSetting();
    virtual ~CSetting();
    CC_SYNTHESIZE_RETAIN(TMXTiledMap*, _pTileMap, TileMap);
};




#endif /* defined(__shootinggamePrototype__CUtil__) */
