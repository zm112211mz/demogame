//
//  GameTypes.h
//  MyGame
//
//  Created by Yin Zhu on 6/9/14.
//
//

#ifndef MyGame_GameTypes_h
#define MyGame_GameTypes_h

enum DripModality
{
    DRIP_MODALITY_CLOUD,
    DRIP_MODALITY_WATER,
    DRIP_MODALITY_ICE,
};

enum DripState
{
    DRIP_STATE_RUNNING,
    DRIP_STATE_JUMPING,
    DRIP_STATE_FLOATING,
    DRIP_STATE_FLYING,
    DRIP_STATE_FALLING,
    DRIP_STATE_MODALITYING,
    DRIP_STATE_DYING,
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
