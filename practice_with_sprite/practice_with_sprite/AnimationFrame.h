#pragma once

#include<d3dx9.h>
#include"Sprite.h"

class AnimationFrame
{
	LPSPRITE sprite;
	DWORD time;

public:
	AnimationFrame(LPSPRITE sprite, int time);
	DWORD GetTime();
	LPSPRITE GetSprite();
};

