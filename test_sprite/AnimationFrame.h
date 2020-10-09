#pragma once
#include"Sprites.h"
#include"Sprite.h"
#include"Game.h"

#include<Windows.h>
#include<d3dx9.h>

class AnimationFrame
{
	LPSPRITE sprite;
	DWORD time;
	
public:
	AnimationFrame(LPSPRITE sprite, int time);
	DWORD GetTime();
	LPSPRITE GetSprite();
};

typedef AnimationFrame* LPANIMATION_FRAME;