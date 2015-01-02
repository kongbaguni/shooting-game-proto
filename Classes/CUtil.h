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
};


#endif /* defined(__shootinggamePrototype__CUtil__) */
