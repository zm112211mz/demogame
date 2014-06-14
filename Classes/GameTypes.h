//
//  GameTypes.h
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#ifndef MyGame_GameTypes_h
#define MyGame_GameTypes_h

enum PlayerType
{
    PLAYER_CLOUD,
    PLAYER_WATER,
    PLAYER_ICE,
};

enum BlockType{
	demoBlockGap,
	demoBlock1,
	demoBlock2,
	demoBlock3,
	demoBlock4
};

enum BalkType
{
    BALK_NONE,
    
    // only cloud
    BALK_FIRE,
    BALK_ROCK,
    
    // only water
    BALK_BIG_BALLNET,
    
    // only ice
    BALK_BIG_GLASS,
    
    // cloud & water
    BALK_BALLNET,
    
    // cloud & ice
    BALK_GLASS,
    
    // water & ice
    BALK_BIRD,
    BALK_BAFFLE,
};

#endif
