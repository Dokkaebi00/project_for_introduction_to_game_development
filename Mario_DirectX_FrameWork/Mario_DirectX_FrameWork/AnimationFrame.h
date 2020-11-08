#pragma once

#include<Windows.h>
#include"Sprite.h"

class Sprite;
typedef Sprite* LPSPRITE;

class AnimationFrame
{
	LPSPRITE sprite;
	DWORD time;
	D3DXVECTOR2 localPosition; //relative postiton with the gameobj;

public:
	AnimationFrame(LPSPRITE sprite, DWORD time, D3DXVECTOR2 localPosition);

	LPSPRITE GetSprite();
	DWORD GetTime();

	~AnimationFrame();
};
typedef AnimationFrame* LPANIMATION_FRAME;