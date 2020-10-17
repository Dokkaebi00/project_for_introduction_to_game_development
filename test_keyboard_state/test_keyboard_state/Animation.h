#pragma once

#include"AnimationFrame.h"
#include"Sprites.h"


class Animation
{
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPANIMATION_FRAME> frames;

public:
	Animation(int defaultTime);
	void Add(int spirteId, DWORD time = 0);
	void Render(float x, float y);
};

