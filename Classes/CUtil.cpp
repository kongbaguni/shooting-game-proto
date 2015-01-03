//
//  CUtil.cpp
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 2..
//
//

#include "CUtil.h"

bool CUtil::isHD()
{
    auto size = Director::getInstance()->getInstance()->getWinSize();
    int sizeTotal = size.width * size.height;
    
    return sizeTotal >= 614400;
}

std::string CUtil::getHDSD()
{
    if(!CUtil::isHD())
    {
        return "-sd";
    }
    
    return "-hd";
}


std::string CUtil::getHDSDname(std::string nameFormat)
{
    auto str = String::createWithFormat(nameFormat.c_str(),getHDSD().c_str());
    return str->_string;
}

Vec3 CUtil::getRotate3D()
{
    return Vec3(90.0f, 0.0f, 0.0f);
}


CSetting* CSetting::getinstance()
{
    static CSetting* instance = NULL;
    if(instance==NULL)
    {
        instance = new CSetting();
    }
    return instance;
}

CSetting::CSetting() :
_pTileMap(NULL)
{
    
}

CSetting::~CSetting()
{
    CC_SAFE_RELEASE_NULL(_pTileMap);
}
