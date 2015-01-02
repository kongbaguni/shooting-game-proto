//
//  CAnimationHelper.h
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 2..
//
//

#ifndef __shootinggamePrototype__CAnimationHelper__
#define __shootinggamePrototype__CAnimationHelper__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class CAnimationHelper
{
public:
    static void addAnimation(std::vector<std::string> frameNameList, std::string animationName);
    static void addAnimation(std::string frameFormat, const int iStartFrame, const int iEndFrame, std::string animationName);
};

#endif /* defined(__shootinggamePrototype__CAnimationHelper__) */
