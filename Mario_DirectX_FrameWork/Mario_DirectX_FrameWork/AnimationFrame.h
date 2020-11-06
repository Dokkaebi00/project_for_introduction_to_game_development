#pragma once

#include<Windows.h>
#include"Sprite.h"



class AnimationFrame
{
	LPSPRITE sprite;
	DWORD time;
	D3DXVECTOR2 position;

public:
	AnimationFrame(LPSPRITE sprite, DWORD time, D3DXVECTOR2 position);

	LPSPRITE GetSprite();
	DWORD GetTime();

	~AnimationFrame();
};
typedef AnimationFrame* LPANIMATION_FRAME;