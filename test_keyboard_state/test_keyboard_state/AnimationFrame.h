#pragma once

#include"Sprite.h"
#include<Windows.h>

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
