//
//  CPlayerSprite.h
//  shootinggamePrototype
//
//  Created by SeoChangyul on 2015. 1. 2..
//
//

#ifndef __shootinggamePrototype__CPlayerSprite__
#define __shootinggamePrototype__CPlayerSprite__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class CPlayerSprite : public Node
{
public:
    virtual bool init();
    CREATE_FUNC(CPlayerSprite);
protected:
    CPlayerSprite(void);
    virtual ~CPlayerSprite(void);
    virtual void update(float dt);
    CC_SYNTHESIZE_RETAIN(Sprite*, m_pSprite, Sprite);
};

#endif /* defined(__shootinggamePrototype__CPlayerSprite__) */
