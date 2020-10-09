#pragma once
#include"AnimationFrame.h"
#include"Sprite.h"
#include"Game.h"
#include"Textures.h"

#include<Windows.h>
#include<d3dx9.h>

class Animation
{
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPANIMATION_FRAME> frames;

public:
	Animation(int defaultTime);
	void Add(int SpriteId, DWORD time = 0);
	void Render(float x, float y);
};

typedef Animation* LPANIMATION;