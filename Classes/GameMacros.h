//
//  GameMacros.h
//  MyGame
//
//  Created by Yin Zhu on 6/15/14.
//
//

#ifndef MyGame_GameMacros_h
#define MyGame_GameMacros_h

/*
 * define a scene function for a  Layer
 * @param \__TYPE__  class type of Layer
 */
#define SCENE_FUNC(__TYPE__) \
static cocos2d::Scene* createScene() \
{ \
__TYPE__* t = __TYPE__::create(); \
cocos2d::Scene* scene = cocos2d::Scene::create(); \
scene->addChild(t); \
return scene; \
}

#define BALK_SPRITE_WIDTH  100
#define BALK_SPRITE_HEIGHT 100

#endif
